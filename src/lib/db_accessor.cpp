#include "db_accessor.h"
#include <sstream>

DbAccessor::DbAccessor(std::string ip_address, std::string user, std::string password):
s_driver{get_driver_instance()},
s_connection{s_driver->connect(ip_address, user, password)}
{
	sql::Statement* statement = s_connection->createStatement();
	statement->execute("USE homeauto_db");
}

void DbAccessor::add_device(const DeviceInfo& device){
	sql::PreparedStatement* statement;
	statement = s_connection->prepareStatement(ADD_DEVICE_QUERY);
	statement->setString(1, device.mac_address);
	statement->setString(2, device.mqtt_topic);
	statement->setString(3, device.is_output ? "OUTPUT" : "INPUT");
	statement->setBoolean(4, device.is_analog);

	statement->execute();
	
}

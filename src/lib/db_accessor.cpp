#include "db_accessor.h"
#include <sstream>

DbAccessor::DbAccessor(std::string ip_address, std::string user, std::string password):
s_driver{get_driver_instance()},
s_connection{s_driver->connect(ip_address, user, password)},
s_statement{s_connection->createStatement()}//std::make_unique<sql::Statement>(s_connection->createStatement());
{
	s_statement->execute("USE homeauto_db");
}

void DbAccessor::add_device(std::string mac_address, std::string mqtt_topic, bool is_output, bool is_analog){
	/*
	std::ostringstream oss;
	oss << "INSERT INTO devices (MacAddress, MqttTopic, Type, IsAnalog) VALUES (\""
		<< mac_address << "\", \"" << mqtt_topic << "\", \"" << (is_output ? "output" : "input")
		<< "\", " <<  is_analog << ")";
	s_statement->execute(oss.str());
	*/
}

/*
int main(){
	DbAccessor db("localhost", "root", "JwKc2000");
	//db.add_device("00:00:00:02", "Topic2", true, false);
}
*/

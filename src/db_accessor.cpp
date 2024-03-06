#include "db_accessor.h"

DbAccessor::DbAccessor(std::string ip_address, std::string user, std::string password):
s_driver{get_driver_instance()},
s_connection{s_driver->connect(ip_address, user, password)},
s_statement{s_connection->createStatement()}//std::make_unique<sql::Statement>(s_connection->createStatement());
{
	s_statement->execute("USE homeauto_db");
	std::unique_ptr<sql::ResultSet> s_result{s_statement->executeQuery("SELECT * FROM devices")};
	while(s_result->next()){
		std::cout << s_result->getString("MacAddress") << '\t';
		std::cout << s_result->getString("MqttTopic") << '\t';
		std::cout << s_result->getString("Type") << '\t';
		std::cout << s_result->getBoolean("IsAnalog") << '\n';
	}
}

void DbAccessor::add_device(std::string mac_address, std::string mqtt_topic, bool is_output, bool is_analog){
}

int main(){
	DbAccessor db("localhost", "root", "JwKc2000");
}

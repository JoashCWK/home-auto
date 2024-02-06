#include "db_accessor.h"

DbAccessor::DbAccessor(std::string ip_address, std::string user, std::string password):
s_driver(new get_driver_instance()),
s_connection(new s_driver->connect(ip_address, user, password)),
s_statement(new s_connection->createStatement())//std::make_unique<sql::Statement>(s_connection->createStatement());
{}

void DbAccessor::add_device(std::string mac_address, std::string mqtt_topic, bool is_output, bool is_analog){

}

int main(){
	DbAccessor db("localhost", "root", "JwKc2000");
}

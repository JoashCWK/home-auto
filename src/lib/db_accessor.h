#ifndef INCLUDED_DB_ACCESSOR
#define INCLUDED_DB_ACCESSOR

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "../util/device_info.h"

class DbAccessor{
	public:
		DbAccessor(std::string ip_address, std::string user, std::string password);
		void add_device(const DeviceInfo& device);
		void add_schedulestd();
	
	private:
		sql::Driver* s_driver;
		std::unique_ptr<sql::Connection> s_connection;
};

const std::string ADD_DEVICE_QUERY = "INSERT INTO devices (MacAddress, MqttTopic, Type, IsAnalog) VALUES (?, ?, ?, ?)";

#endif

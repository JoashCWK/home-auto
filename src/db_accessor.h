#ifndef INCLUDED_DB_ACCESSOR
#define INCLUDED_DB_ACCESSOR

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class DbAccessor{
	public:
		DbAccessor(std::string ip_address, std::string user, std::string password);
		void add_device(std::string mac_address, std::string mqtt_topic, bool is_output, bool is_analog);
	
	private:
		sql::Driver* s_driver;
		std::unique_ptr<sql::Connection> s_connection;
		std::unique_ptr<sql::Statement> s_statement;
};

#endif

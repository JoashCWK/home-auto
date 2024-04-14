#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

int main(){
	sql::Driver* driver{get_driver_instance()};
	std::unique_ptr<sql::Connection> con(driver->connect("localhost", "root", "JwKc2000"));
	//con->setSchema("homeauto_db");
	std::unique_ptr<sql::Statement> stmt(con->createStatement());

	// We need not check the return value explicitly. If it indicates
	// an error, Connector/C++ generates an exception.
	stmt->execute("USE homeauto_db");
	std::string insert = "INSERT INTO devices (MacAddress, MqttTopic, Type, IsAnalog) VALUES (\"00:00:00:01\", \"Light2\", \"output\", 0)";
	//std::cout << insert << std::endl;
	//stmt->execute(insert);
	std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM devices"));

	while(res->next()){
		std::cout << res->getString("MacAddress") << '\t';
		std::cout << res->getString("MqttTopic") << '\t';
		std::cout << res->getString("Type") << '\t';
		std::cout << res->getBoolean("IsAnalog") << '\n';
	}
}

#include "msg_processor.h"
#include "../util/device_info.h"
#include <iostream>


std::string exec_cmd(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

MsgProcessor::MsgProcessor(DbAccessor& dbAccessor)
: s_dbAccessor{std::move(dbAccessor)}{}

MqttMessage MsgProcessor::process(const MqttMessage& msg){
	if(msg.topic == "setDevice")
	{
		std::cout << "Set Device Message Received" << std::endl;
		std::string mac_address = exec_cmd("bash ../http/get_mac.sh " + msg.payload);

		std::cout << "To add to database and publish success response: " << mac_address << std::endl;

		MqttMessage m;
		m.topic = "addTopicResponse";
		m.payload = "success";
		return m;
	}
	else if(msg.topic == "getDevices")
	{

	}
	else if(msg.topic == "setSchedule")
	{
		
	}

	else if(msg.topic == "getSchedules")
	{

	}

	return MqttMessage();

}

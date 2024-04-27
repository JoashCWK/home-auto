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

MsgProcessor::MsgProcessor(
	const std::string& IPAddress,
	const std::string& userName,
	const std::string& password
): s_dbAccessor(IPAddress, userName, password)
{}

mqtt::const_message_ptr MsgProcessor::process(mqtt::const_message_ptr msg){
	return process(msg->get_topic(), msg->to_string());
}

mqtt::const_message_ptr MsgProcessor::process(const std::string& topic, const std::string& payload){
	if(topic == "setDevice")
	{
		std::cout << "Set Device Message Received" << std::endl;
		std::string mac_address = exec_cmd("bash ../http/get_mac.sh " + payload);

		std::cout << "To add to database and publish success response: " << mac_address << std::endl;

		return mqtt::make_message("setDeviceResponse", "1");
	}
	else if(topic == "getDevices")
	{

	}
	else if(topic == "setSchedule")
	{
		
	}

	else if(topic == "getSchedules")
	{

	}

	return nullptr;
}

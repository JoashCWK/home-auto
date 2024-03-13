#include "mqtt_client.h"
#include <iostream>

#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>


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

MqttClient::MqttClient(const std::string& ip, const std::string& id)
: s_client(ip, id, mqtt::create_options(MQTTVERSION_5)){
	s_client.connect();
	s_client.start_consuming();
}

void MqttClient::publish_message(const std::string& topic, const std::string& payload){
	mqtt::message_ptr ptr = mqtt::make_message(topic, "");
	ptr->set_payload(payload);
	s_client.publish(ptr);
}

void MqttClient::subscribe_topics(const std::vector<std::string>& topics){
	for(auto i : topics){
		s_client.subscribe(i);
	}
}

void MqttClient::subscribe_topic(const std::string& topic){
	s_client.subscribe(topic);
}

struct MqttMessage MqttClient::read_message(){
	auto consumed_msg = s_client.consume_message();
	return MqttMessage{consumed_msg->get_topic(), consumed_msg->to_string()};
}



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
	: client(ip, id, mqtt::create_options(MQTTVERSION_5)){
	client.connect();
	client.start_consuming();
}

void MqttClient::publish_message(const std::string& topic, const std::string& payload){
	mqtt::message_ptr ptr = mqtt::make_message(topic, "");
	ptr->set_payload(payload);
	client.publish(ptr);
}

void MqttClient::subscribe_topics(const std::vector<std::string>& topics){
	for(auto i : topics){
		client.subscribe(i);
	}
}

void MqttClient::subscribe_topic(const std::string& topic){
	client.subscribe(topic);
}

struct MqttMessage MqttClient::read_message(){
	struct MqttMessage msg;

	/*
	if(client.try_consume_message(&ptr)){
		msg.isValid = true;
		msg.topic = ptr -> get_topic();
		msg.payload = ptr -> get_payload_str();
	}
	*/

	auto a = client.consume_message();
	msg.isValid = true;
	msg.topic = a->get_topic();
	msg.payload = a->to_string();

	return msg;
}

void MqttClient::process_message(const MqttMessage& msg){
	std::cout << msg.topic << ": " << msg.payload << std::endl;
	if(msg.topic == "addTopic"){
		std::cout << exec_cmd("bash http/get_mac.sh " + msg.payload) << std::endl;
		subscribe_topic(msg.payload + "/task");
		subscribe_topic(msg.payload + "/state");
	}
}

#include "mqtt_handler.h"

MQTT_Handler::MQTT_Handler(const std::string& ip, const std::string& id)
	: client(ip, id, mqtt::create_options(MQTTVERSION_5)){
	client.connect();
}

void MQTT_Handler::publish_message(const std::string& topic, const std::string& payload){
	mqtt::message_ptr ptr = mqtt::make_message(topic, "");
	ptr->set_payload(payload);
	client.publish(ptr);
}

void MQTT_Handler::subscribe_topics(const std::vector<std::string>& topics, uint8_t num_topics){
	for(auto i : topics){
		client.subscribe(i);
	}
	client.start_consuming();
}

struct MQTT_Message MQTT_Handler::read_message(){
	struct MQTT_Message msg;
	mqtt::const_message_ptr ptr;
	if(client.try_consume_message(&ptr)){
		msg.isValid = true;
		msg.topic = ptr -> get_topic();
		msg.payload = ptr -> get_payload_str();
	}

	return msg;
}



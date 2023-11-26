#include "mqtt_handler.h"

using namespace std;

MQTT_Handler::MQTT_Handler(string ip, string id)
	: client(ip, id, mqtt::create_options(MQTTVERSION_5)){
	client.connect();
}

void MQTT_Handler::publish_message(string topic, string payload){
	mqtt::message_ptr ptr = mqtt::make_message(topic, "");
	ptr->set_payload(payload);
	client.publish(ptr);
}

void MQTT_Handler::subscribe_topics(string* topics, uint8_t num_topics){
	for(uint8_t i=0; i<num_topics; i++){
		client.subscribe(topics[i]);
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



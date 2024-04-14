#ifndef INCLUDED_EVENT_HANDLER
#define INCLUDED_EVENT_HANDLER

#include "mqtt_client.h"
#include "msg_processor.h"

class EventHandler{
	public:
		EventHandler(std::unique_ptr<MqttClient> mqttClient, std::unique_ptr<MsgProcessor> msgProcessor);
		void run();

	private:
		const std::unique_ptr<MqttClient> s_mqttClient;
		const std::unique_ptr<MsgProcessor> s_msgProcessor;
};


#endif

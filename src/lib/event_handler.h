#ifndef INCLUDED_EVENT_HANDLER
#define INCLUDED_EVENT_HANDLER

#include "mqtt_client.h"
#include "msg_processor.h"

class EventHandler{
	public:
		EventHandler(MqttClient* mqttClient, MsgProcessor& msgProcessor);
		void run();

	private:
		MqttClient* s_mqttClient;
		MsgProcessor s_msgProcessor;
};


#endif

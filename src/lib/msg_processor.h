#ifndef INCLUDED_MSG_PROCESSOR
#define INCLUDED_MSG_PROCESSOR

#include "mqtt_message.h"
#include "db_accessor.h"
#include "mqtt_client.h"

class MsgProcessor{
	public:
		MsgProcessor(MqttClient* mqttClient, DbAccessor* dbAccessor);
		void process(const MqttMessage& msg);

	private:
		MqttClient* s_mqttClient;
		DbAccessor* s_dbAccessor;
};

#endif

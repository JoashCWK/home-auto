#ifndef INCLUDED_MSG_PROCESSOR
#define INCLUDED_MSG_PROCESSOR

#include "mqtt_message.h"

class MsgProcessor{
	public:
		void process(const MqttMessage& msg);
};

#endif

#ifndef INCLUDED_MSG_PROCESSOR
#define INCLUDED_MSG_PROCESSOR

#include "../util/mqtt_message.h"
#include "db_accessor.h"

class MsgProcessor{
	public:
		MsgProcessor(DbAccessor& dbAccessor);
		MqttMessage process(const MqttMessage& msg);

	private:
		DbAccessor s_dbAccessor;
};

#endif

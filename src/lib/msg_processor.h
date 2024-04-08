#ifndef INCLUDED_MSG_PROCESSOR
#define INCLUDED_MSG_PROCESSOR

#include "../util/mqtt_message.h"
#include "db_accessor.h"

class MsgProcessor{
	public:
		MsgProcessor(std::unique_ptr<DbAccessor> dbAccessor);
		MqttMessage process(const MqttMessage& msg);

	private:
		const std::unique_ptr<DbAccessor> s_dbAccessor;
};

#endif

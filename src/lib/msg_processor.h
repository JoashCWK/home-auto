#ifndef INCLUDED_MSG_PROCESSOR
#define INCLUDED_MSG_PROCESSOR

#include "db_accessor.h"
#include "../util/mqtt_message.h"
#include <mqtt/async_client.h>

class MsgProcessor{
	public:
		MsgProcessor(std::unique_ptr<DbAccessor> dbAccessor);
		
		mqtt::const_message_ptr process(mqtt::const_message_ptr msg);
		mqtt::const_message_ptr process(const std::string& topic, const std::string& payload);

	private:
		const std::unique_ptr<DbAccessor> s_dbAccessor;
};

#endif

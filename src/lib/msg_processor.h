#ifndef INCLUDED_MSG_PROCESSOR
#define INCLUDED_MSG_PROCESSOR

#include "db_accessor.h"
#include <mqtt/async_client.h>

class MsgProcessor{
	public:
		MsgProcessor(
			const std::string& IPAddress,
			const std::string& userName,
			const std::string& password
		);

		mqtt::const_message_ptr process(mqtt::const_message_ptr msg);
		mqtt::const_message_ptr process(const std::string& topic, const std::string& payload);

	private:
		const DbAccessor s_dbAccessor;
};

#endif

#ifndef INCLUDED_EVENT_HANDLER
#define INCLUDED_EVENT_HANDLER

#include "msg_processor.h"
#include <mqtt/async_client.h>

class EventHandler: public virtual mqtt::callback
{
	public:
		EventHandler(
			const std::string& IPAddress,
			const std::string& name,
			const std::string& dbUsername,
			const std::string& dbPassword
		);

	private:
		mqtt::async_client s_mqttAsyncClient;
		MsgProcessor s_msgProcessor;

		void connected(const std::string& cause) override;
		void connection_lost(const std::string& cause) override{}

		void message_arrived(mqtt::const_message_ptr msg) override;
		void delivery_complete(mqtt::delivery_token_ptr token) override{}

		std::vector<std::string> s_topics = {"setDevice", "schedule"};
};


#endif

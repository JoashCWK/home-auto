#include <mqtt/client.h>

using namespace std;

struct MQTT_Message{
	string topic;
	string payload;
	bool isValid = false;
};

class MQTT_Handler{
	private:
		mqtt::client client;
	public:
		MQTT_Handler(string, string);
		void publish_message(string topic, string payload);
		void subscribe_topics(string* topics, uint8_t num_topics);
		struct MQTT_Message read_message();
};



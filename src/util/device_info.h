#ifndef INCLUDED_DEVICE_INFO
#define INCLUDED_DEVICE_INFO

#include <string>

struct DeviceInfo{
	std::string configuredName;
	std::string deviceName;
	std::string macAddress;
	std::string room;
	std::string mqttTopic;
	bool isOutput;
	bool isAnalog;
	int deviceCode;
};

#endif

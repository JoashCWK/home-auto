#ifndef INCLUDED_DEVICE_INFO
#define INCLUDED_DEVICE_INFO

#include <string>

struct DeviceInfo{
	std::string mac_address;
	std::string mqtt_topic;
	bool is_output;
	bool is_analog;
};

#endif

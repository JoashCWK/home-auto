#ifndef INCLUDED_DEVICE_SERVER
#define INCLUDED_DEVICE_SERVER

#include <iostream>
#include <boost/asio.hpp>
#include "../util/device_info.h"

namespace {
	using namespace boost::asio;
	using namespace boost::asio::ip;
}

class DeviceServer{
	public:
		DeviceServer(int port, int timeout);
		bool setupDevice(DeviceInfo& deviceInfo, std::string configuredName, std::string room);

	private:
		int _port;
		int _timeout;
};


#endif

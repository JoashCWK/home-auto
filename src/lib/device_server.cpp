#include "device_server.h"
#include <iostream>

namespace {
	using namespace boost::asio;
	using namespace boost::asio::ip;
}

DeviceServer::DeviceServer(int port, int timeout)
: _port(port)
, _timeout(timeout)
{}

bool DeviceServer::setupDevice(DeviceInfo& deviceInfo, std::string configuredName, std::string room){
	bool hasConnection = false;

	io_service io;
	tcp::endpoint endpoint(tcp::v4(), _port);
	tcp::acceptor acceptor(io, endpoint);

	std::cout << "Server started. Listening on port " << _port << std::endl;

	deadline_timer timer(io);
	timer.expires_from_now(boost::posix_time::seconds(_timeout));
	timer.async_wait([&io](const boost::system::error_code& error){
		std::cout << "Connection timed out" << std::endl;
		io.stop();
	});

	tcp::socket socket(io);
	acceptor.async_accept(socket, [&timer, &hasConnection](const boost::system::error_code& error){
		timer.cancel();
		hasConnection = true;
		std::cout << "New HTTP connection established" << std::endl;
	});
	
	io.run();

	if(hasConnection){
		streambuf request_buf;
		read_until(socket, request_buf, "\r\n\r\n");

		std::string request = buffer_cast<const char*>(request_buf.data());
		size_t pos = request.find("{");
		std::string body = request.substr(pos);
		std::cout << "Body: " << body << std::endl;

		std::ostringstream oss;
		std::string response = "HTTP/1.1 200 OK\r\nContent-Length: ";
		oss << response << (int)(21 + configuredName.length() + room.length()) << "\r\n\r\nconfiguredName=" << configuredName << "&room=" << room;

		boost::asio::write(socket, boost::asio::buffer(oss.str()));

	}
	socket.close();

	return hasConnection;

}

int main(){
	DeviceInfo d;
	DeviceServer s(8080, 10);
	if(s.setupDevice(d, "Lights", "LivingRoom")){
		std::cout << "Done!" << std::endl;
	}
}

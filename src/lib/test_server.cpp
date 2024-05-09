#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_service io;

    // Create an endpoint for accepting connections
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 8080);

    // Create and open a socket for accepting connections
    boost::asio::ip::tcp::acceptor acceptor(io, endpoint);

    std::cout << "Server started. Listening on port 8080..." << std::endl;

	// Create a socket for the next incoming connection
	boost::asio::ip::tcp::socket socket(io);

	// Wait for and accept a new connection
	acceptor.accept(socket);

	// Read the HTTP request
	boost::asio::streambuf request;
	boost::asio::read_until(socket, request, "\r\n\r\n");

	// Convert the request to a string and print it
	std::istream request_stream(&request);
	std::string request_string;
	std::getline(request_stream, request_string);
	std::cout << "Received HTTP request:\n" << request_string << std::endl;

	// Send a simple HTTP response
	std::string response = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello World!";
	boost::asio::write(socket, boost::asio::buffer(response));
	socket.close();

    return 0;
}

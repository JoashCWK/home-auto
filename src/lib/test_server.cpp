#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    boost::asio::io_service io;
    bool hasConnection = false;

    // Create an endpoint for accepting connections
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 8080);

    // Create and open a socket for accepting connections
    boost::asio::ip::tcp::acceptor acceptor(io, endpoint);

    std::cout << "Server started. Listening on port 8080..." << std::endl;

	deadline_timer accept_deadline(io);
	accept_deadline.expires_from_now(boost::posix_time::seconds(3));
    accept_deadline.async_wait([&acceptor, &io](const boost::system::error_code& error) {
		if(!error){
			std::cout << "Accepting connections timed out." << std::endl;
			io.stop();
		}
    });

    std::cout << "Creating socket" << std::endl;

	// Create a socket for the next incoming connection
	boost::asio::ip::tcp::socket socket(io);

	// Wait for and accept a new connection
	acceptor.async_accept(socket, [&accept_deadline, &hasConnection](const boost::system::error_code& error) {
        // Cancel the timer since a connection attempt was made
        accept_deadline.cancel();
        hasConnection = true;
        if (!error) {
            // Handle the new connection
            std::cout << "New HTTP connection established" << std::endl;
            // Implement your logic for handling the HTTP connection here
        } else {
            std::cerr << "Error accepting connection: " << error.message() << std::endl;
        }
    });

	io.run();

	if(hasConnection){
		std::cout << "Reading request" << std::endl;
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
	}

    return 0;
}

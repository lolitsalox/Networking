#include <iostream>
#include "NetworkException.hpp"
#include "AutoWSA.hpp"
#include "Socket.hpp"

int main()
{
    try
    {
        Network::AutoWSA::s_initialize();
        const auto socket = std::make_unique<Network::Socket>();

        socket->connect(Network::EndpointIPv4(L"142.250.75.78", 80));

        std::string request = "GET / HTTP/1.1\r\nHost: google.com\r\nUserAgent: NetworkExe\r\n\r\n";

        socket->send(Buffer(request.begin(), request.end()));
        Buffer buffer = socket->receive();
        std::cout << buffer.data() << std::endl;
    }
    catch (const Network::Exception& e)
    {
        std::cout << "Caught a network exception: [" << e.code() << "]: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught an exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cout << "Caught an unknown exception!\n";
    }
}

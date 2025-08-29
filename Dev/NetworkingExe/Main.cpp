#include <iostream>
#include <thread>
#include <print>

#include "NetworkException.hpp"
#include "AutoWSA.hpp"
#include "Socket.hpp"
#include "TcpServer.hpp"


int main()
{
    static constexpr uint16_t PORT = 6969;

    try
    {
        Network::AutoWSA::s_initialize();

        std::vector<std::thread> threads(10);

        for (uint32_t i = 0; i < 10; ++i)
        {
            threads.emplace_back([i]()
                {
                    Network::Socket server(Network::EndpointIPv4::s_get_loopback_endpoint(PORT));
                    std::println("Server: {}", reinterpret_cast<char*>(server.receive().data()));
                    server.send(BufferUtils::container_to_buffer(std::to_string(i) + ": Hello back from client!"));
                });
        }

        std::vector<std::thread> server_threads;
        Network::TcpServer server(PORT);

        auto client_handler = [](Network::SocketUPtr client)
        {
            client->send(BufferUtils::container_to_buffer(std::string("Hello from server!")));
            std::println("Client: {}", reinterpret_cast<char*>(client->receive().data()));
        };
        
        auto connect_handler = [&server, &server_threads, &client_handler]()
        {
            while (true)
            {
                server_threads.emplace_back(client_handler, server.accept());
            }
        };
        
        std::thread connector(connect_handler);
        connector.join();
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

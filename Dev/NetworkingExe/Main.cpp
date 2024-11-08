#include <iostream>
#include <thread>
#include "NetworkException.hpp"
#include "AutoWSA.hpp"
#include "Socket.hpp"
#include "TcpServer.hpp"

class JoinableThread
{
public:
    template<typename... TArgs>
    JoinableThread(TArgs... args) : m_thread(std::forward<TArgs>(args)...) {}
    virtual ~JoinableThread() { m_thread.join(); }

private:
    std::thread m_thread;
};

int main()
{
    static constexpr uint16_t PORT = 6969;

    try
    {
        Network::AutoWSA::s_initialize();

        std::vector<std::thread> threads;

        for (uint32_t i = 0; i < 10; ++i)
        {
            threads.emplace_back([i]()
                {
                    Network::Socket server(Network::EndpointIPv4::s_get_loopback_endpoint(PORT));
                    std::wcout << (wchar_t*)server.receive().data() << std::endl;
                    server.send(BufferUtils::container_to_buffer(std::to_wstring(i) + L": Hello back from client!"));
                });
        }

        Network::TcpServer server(PORT);

        while (true)
        {
            Network::SocketUPtr client = server.accept();
            client->send(BufferUtils::container_to_buffer(std::wstring(L"Hello from server!")));
            std::wcout << (wchar_t*)client->receive().data() << std::endl;
        }
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

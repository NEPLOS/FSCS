
#include "server.h"
#include <iostream>

Server::Server()
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    setupRoutes();

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(SERVER_PORT);

    if (bind(serverSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        std::cerr << "nope this shi is broken";
        exit(1);
    }

    if (listen(serverSocket, SERVER_BACKLOG) == -1)
    {
        std::cerr << "nope this shi is broken 2 ";
        exit(1);
    }

    std::cout << "here 1\n";

    while (true)
    {
        sleep(1);
        addrSize = sizeof(sockaddr);

        clientSocket = accept(serverSocket, (sockaddr *)&clientAddr, (socklen_t *)&addrSize);

        handleConnection(clientSocket);
    }
}

void Server::setupRoutes()
{

    router.addRoute(GET, "/home", [](Params &prams) -> std::string
                    {
                        return "hello from /home , method : GET \n";
                    });
    router.addRoute(GET, "/setting", [](Params &prams) -> std::string
                    {
                        return "hello from /setting , method : GET \n";
                    });
    router.addRoute(GET, "/home/setting", [](Params &prams) -> std::string
                    {
                        return "hello from /home/setting , method : POST \n";
                    });

    router.addRoute(GET, "/home/{test}", [](Params &prams) -> std::string
                    {
                        std::string t = prams["test"];
                        return "hello from /home/{test}  , method : GET , pram : " + t + "\n";
                    });

    router.addRoute(GET, "/home/{test}/{test2}", [](Params &prams) -> std::string
                    {
                        std::string t = prams["test"];
                        std::string t2 = prams["test2"];
                        return t + "-" + t2 + "\n";
                    });

    router.addRoute(GET, "/{userName}/{setting}", [](Params &prams) -> std::string
                    {
                        std::string t = prams["userName"];
                        std::string tt = prams["setting"];
                        return "user name = " + t + " - other one : " + tt + "\n";
                    });

    router.addRoute(GET, "/support", [](Params &prams) -> std::string
                    {

                        return "--- this is for the support page ---\n";
                    });

    router.addRoute(GET, "/", [](Params &prams) -> std::string
                    {
                        std::cout << "-- this is root --\n";

                        return "--- hello from root ---\n";
                    });

    router.addRoute(GET, "/FSCS", [](Params &prams) -> std::string
                    {
                        return "--- welcome to our mini cloud server FSCS ---\n";
                    });
}

void Server::handleConnection(int clientSocket)
{
    std::string buffer;
    buffer.reserve(4096);

    char temp[1024];
    
    Request usersRequest;
    
    
    ssize_t n;
    
    
    while ((n = read(clientSocket, temp, sizeof(temp))) > 0)
    {
        
       // std::cout << temp << '\n';

        buffer.append(temp, n);
        usersRequest.parseBuffer(buffer);
        
        if (buffer.find("\r\n\r\n") != std::string::npos)
        break;
    }

    if (buffer.empty())
    {
        close(clientSocket);
        return;
    }

    usersRequest.printHeader();

    std::string text = router.handleRequest(usersRequest.method , usersRequest.path);

    std::string response =
    "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: " + std::to_string(text.size()) + "\r\n"
        "\r\n" +    
        text;

    write(clientSocket, response.c_str(), response.size());
    close(clientSocket);
}

Server::~Server()
{
}
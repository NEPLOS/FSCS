
#include <string>
#include <sys/socket.h>
#include <limits>
#include <arpa/inet.h>
#include <unistd.h>
#include "router.h"
#include "request.h"

#define SERVER_PORT 8080
#define SERVER_BACKLOG 10

class Server
{
public:

    int serverSocket;
    int clientSocket;
    int addrSize;

    sockaddr_in serverAddr;
    sockaddr_in clientAddr;

    Router router;

    Server();
    ~Server();
    void handleConnection(int clientSocket);

    void setupRoutes();

};
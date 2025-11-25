#include <iostream>
#include "../include/request.h"

int main(int argc, char *argv[])
{
    std::cout << "beeg boom" << std::endl;

    Request req;

    std::string buffer = "GET / HTTP/1.1\r\nHOST: mozila\r\nAccount: test\r\n\r\nbody\r\n"; 

    req.parseBuffer(buffer);

    // req.handleStartLine("GET / HTTP/1.1\r\n");
    // req.parseEachLine("HOST: mozila");
    // req.parseEachLine("Accept: */*");
    // req.parseEachLine("Content-Length: 12");
    // req.parseEachLine("User-Agent: curl/8.6.0");

    std::cout << "buffer ->" << buffer << '\n';
    req.printHeader();

}

#include <iostream>
#include "../include/request.h"
#include "../include/router.h"
#include "../include/MySql.h"
#include "server.h"

typedef std::unordered_map<std::string , std::string> Params;

int main(int argc, char *argv[])
{

    // Request usersRequest;

    // std::string req = "GET /home/{test} HTTP/1.1\r\n"
    //                   "Host: example.com\r\n"
    //                   "Token: iuahepouharo\r\n"
    //                   "Accept: */*\r\n";              

    // usersRequest.parseBuffer(req);


    Server s;
    

    //router.handleRequest(usersRequest.method , usersRequest.path);

    // router.handleRequest("home/NEPLOS/oijhgq[h]");
    // router.handleRequest("home/NEPLOS");



}

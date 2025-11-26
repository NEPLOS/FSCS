#include <iostream>
#include "../include/request.h"
#include "../include/router.h"
#include "../include/MySql.h"

int main(int argc, char *argv[])
{
    Router router;

    router.addRoute( GET , "/home/setting" , [](std::unordered_map<std::string , std::string>& prams){

        std::cout << "hello from /home/setting , method : GET \n";

    });
    router.addRoute( POST ,  "/home/setting" , [](std::unordered_map<std::string , std::string>& prams){

        std::cout << "hello from /home/setting , method : POST \n";

    });

    router.addRoute( GET ,  "/home/{test}", [](std::unordered_map<std::string , std::string>& prams)
    {
        std::string t = prams["test"];
        std::cout << "hello from /home/{test}  , method : GET , pram : " << t << "\n";

    });

    router.addRoute(GET , "/home/{test}/{test2}", [](std::unordered_map<std::string , std::string>& prams)
    {
        std::string t = prams["test"];
        std::string t2 = prams["test2"];
        std::cout << t << "-" << t2 << "\n";

    });

    router.addRoute(GET , "/{userName}/{setting}", [](std::unordered_map<std::string , std::string>& prams)
    {
        std::string t = prams["userName"];
        std::string tt = prams["setting"];
        std::cout << "user name = " << t << " - other one : " << tt << "\n";

    });

    router.addRoute(GET , "/support", [](std::unordered_map<std::string , std::string>& prams)
    {
        // std::string t = prams["userName"];
        // std::string tt = prams["setting"];
        // std::cout << "user name = " << t << " - other shit : " << tt << "\n";

        std::cout << "--- this is for the support page ---\n";

    });

    router.addRoute(GET , "/", [](std::unordered_map<std::string , std::string>& prams)
    {
        // std::string t = prams["userName"];
        // std::string tt = prams["setting"];
        // std::cout << "user name = " << t << " - other shit : " << tt << "\n";

        std::cout << "--- hello from root ---\n";

    });

    Request usersRequest;

    std::string req = "GET /home/FSCS HTTP/1.1\r\n"
                      "Host: example.com\r\n"
                      "Accept: */*\r\n";              

    usersRequest.parseBuffer(req);

    router.handleRequest(GET , "/home/fwat4a");

    // router.handleRequest("home/NEPLOS/oijhgq[h]");
    // router.handleRequest("home/NEPLOS");



}

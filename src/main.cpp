#include <iostream>
#include "../include/request.h"
#include "../include/router.h"
#include "../include/MySql.h"

typedef std::unordered_map<std::string , std::string> Params;

int main(int argc, char *argv[])
{
    Router router;

    router.addRoute(GET , "/home/setting" , [](Params& prams){

        std::cout << "hello from /home/setting , method : GET \n";

    });
    router.addRoute(POST ,  "/home/setting" , [](Params& prams){

        std::cout << "hello from /home/setting , method : POST \n";

    });

    router.addRoute(GET ,  "/home/{test}", [](Params& prams)
    {
        std::string t = prams["test"];
        std::cout << "hello from /home/{test}  , method : GET , pram : " << t << "\n";

    });

    router.addRoute(GET , "/home/{test}/{test2}", [](Params& prams)
    {
        std::string t = prams["test"];
        std::string t2 = prams["test2"];
        std::cout << t << "-" << t2 << "\n";

    });

    router.addRoute(GET , "/{userName}/{setting}", [](Params& prams)
    {
        std::string t = prams["userName"];
        std::string tt = prams["setting"];
        std::cout << "user name = " << t << " - other one : " << tt << "\n";

    });

    router.addRoute(GET , "/support", [](Params& prams)
    {
        // std::string t = prams["userName"];
        // std::string tt = prams["setting"];
        // std::cout << "user name = " << t << " - other shit : " << tt << "\n";

        std::cout << "--- this is for the support page ---\n";

    });


    router.addRoute(GET , "/", [](Params& prams)
    {
        // std::string t = prams["userName"];
        // std::string tt = prams["setting"];
        // std::cout << "user name = " << t << " - other shit : " << tt << "\n";

        std::cout << "--- hello from root ---\n";

    });


    router.addRoute(GET , "/FSCS", [](Params& prams)
    {

        std::cout << "--- welcome to our mini cloud server FSCS ---\n";

    });

    Request usersRequest;

    std::string req = "GET /home/{test} HTTP/1.1\r\n"
                      "Host: example.com\r\n"
                      "Token: iuahepouharo\r\n"
                      "Accept: */*\r\n";              

    usersRequest.parseBuffer(req);

    router.handleRequest(usersRequest.method , usersRequest.path);

    // router.handleRequest("home/NEPLOS/oijhgq[h]");
    // router.handleRequest("home/NEPLOS");



}

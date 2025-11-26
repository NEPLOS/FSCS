#include <iostream>
#include "../include/request.h"
#include "../include/router.h"
#include "../include/MySql.h"

int main(int argc, char *argv[])
{
    Router router;

    router.addRoute("/home/setting" , [](std::unordered_map<std::string , std::string>& prams){

        std::cout << "hello from setting \n";

    });

    router.addRoute("/home/{test}", [](std::unordered_map<std::string , std::string>& prams)
    {
        std::string t = prams["test"];
        std::cout << t << "\n";

    });

    router.addRoute("/home/{test}/{test2}", [](std::unordered_map<std::string , std::string>& prams)
    {
        std::string t = prams["test"];
        std::string t2 = prams["test2"];
        std::cout << t << "-" << t2 << "\n";

    });

    router.addRoute("/{userName}/{setting}", [](std::unordered_map<std::string , std::string>& prams)
    {
        std::string t = prams["userName"];
        std::string tt = prams["setting"];
        std::cout << "user name = " << t << " - other shit : " << tt << "\n";

    });

    router.handleRequest("home/NEPLOS/oijhgq[h]");
    router.handleRequest("home/NEPLOS");



}

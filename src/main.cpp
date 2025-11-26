#include <iostream>
#include "../include/request.h"
#include "router.h"

void homeHandler(std::unordered_map<std::string , std::string>& prams)
{
    std::cout << "hello\n";
}

int main(int argc, char *argv[])
{



    Router router;

    router.addRoute("/home/{test}", [](std::unordered_map<std::string , std::string>& prams)
    {
        std::string t = prams["test"];
        std::cout << t << "\n";

    });

    router.handleRequest("/home/salam");

    // router.addRoute("/user/login", homeHandler);
    // router.addRoute("/user/{id}", userHandler);
    // router.addRoute("/post/{postId}/comment/{commentId}", postCommentHandler);
// 



}
    // std::cout << "beeg boom" << std::endl;

    // Request req;

    // std::string buffer = "GET /login HTTP/1.1\r\nHOST: mozila\r\nAccount: test\r\n\r\nbody\r\n"; 

    // std::cout << "request : \n------\n" << buffer << "------\n";

    // /*
    //     MySQLConnection db("localhost" , "root" , "Parham_1" , "new_schema");

    //     res = db.mysqlExecuteQuery("SELECT * FROM user;");


    //     while ((db.row = mysql_fetch_row(db.res)) != NULL)
    //     {
    //         std::cout << db.row[1] << " - " << db.row[2] << '\n';
    //     }
    // */

    // req.parseBuffer(buffer);

    // // req.handleStartLine("GET / HTTP/1.1\r\n");
    // // req.parseEachLine("HOST: mozila");
    // // req.parseEachLine("Accept: */*");
    // // req.parseEachLine("Content-Length: 12");
    // // req.parseEachLine("User-Agent: curl/8.6.0");

    // std::cout << "buffer ->" << buffer << '\n';
    // req.printHeader();


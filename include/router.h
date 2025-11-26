
#ifndef MY_ROUTER_H
#define MY_ROUTER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "trie.h"


// a basic router
class Router
{
private:
    Trie trie;
   // void (*defaulHandler)();

public:
    Router();

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    /**
     *
     *  @brief register a new route in the router
     *
     *  @param method   the HTTP method to associate with this route (GET, POST, ...)
     *  @param path     the URL pattern to register
     *  @param handler  the function to execute when this route matches
     */
    void addRoute(Method method , std::string path, std::function<void(std::unordered_map<std::string, std::string>&)> handler);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    /**
     * @brief Resolve and execute the handler for an incoming request.
     *
     * @param method the request HTTP method
     * @param path the request path
     */
    void handleRequest(Method method , std::string path);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    void setDefaultHandler(std::function<void(std::unordered_map<std::string, std::string>&)> handler);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    void notFoundHandler();

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    /**
    
        @brief print all registered routes for debugging or inspection.

        outputs the trie structure 

    */
    void printAllRoutes();

    /*----------------------------------------------------------------------------------------------------------------------------------*/

};

void notFoundHandler();

#endif




#ifndef MY_ROUTER_H
#define MY_ROUTER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "trie.h"

class Router
{
private:
    Trie trie;
   // void (*defaulHandler)();

public:
    Router();
    void addRoute(Method method , std::string path, std::function<void(std::unordered_map<std::string, std::string>&)> handler);
    void handleRequest(Method method , std::string path);
    void setDefaultHandler(std::function<void(std::unordered_map<std::string, std::string>&)> handler);
    void notFoundHandler();

    void printAllRoutes();

};

void notFoundHandler();

#endif



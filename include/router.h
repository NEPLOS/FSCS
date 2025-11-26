
#ifndef ROUTER_H
#define ROUTER_H

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
    void addRoute(std::string path, std::function<void(std::unordered_map<std::string, std::string>&)> handler);
    void handleRequest(std::string path);
    void setDefaultHandler(std::function<void(std::unordered_map<std::string, std::string>&)> handler);
    void notFoundHandler();
};

void notFoundHandler();

#endif



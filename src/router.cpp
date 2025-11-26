
#include "../include/router.h"

Router::Router()
{
   // defaulHandler = notFoundHandler();
}

void Router::notFoundHandler()
{
    std::cout << "404 Not Found\n";
};

void Router::addRoute(std::string path , std::function<void(std::unordered_map<std::string, std::string>&)> handler)
{
    trie.insertNode(path, handler);
}

void Router::handleRequest(std::string path)
{
    std::unordered_map<std::string, std::string> params;
    Node *node = trie.selectedPath(path, params);
    if (node && node->handler)
    {
        node->handler(params);
    }
    else
        notFoundHandler();
}

void Router::setDefaultHandler(std::function<void(std::unordered_map<std::string, std::string>&)> handler)
{
    notFoundHandler();
}

void Router::printAllRoutes()
{
    std::cout << trie.head->data <<'\n';
    trie.printTrie(trie.head);
}


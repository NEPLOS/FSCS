
#include "../include/router.h"

Router::Router()
{
   // defaulHandler = notFoundHandler();
}

void Router::notFoundHandler()
{
    std::cout << "404 Not Found\n";
};

void Router::addRoute(Method method , std::string path , std::function<void(std::unordered_map<std::string, std::string>&)> handler)
{
    trie.insertNode(method , path, handler);
}

void Router::handleRequest(Method method , std::string path)
{
    std::unordered_map<std::string, std::string> params;
    Node *node = trie.selectedPath(path, params);
    if (node && (node->handler.find(method) != node->handler.end()))
    {
        node->handler[method](params);
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


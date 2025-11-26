
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

        if (!params.empty())
        {
            // std::cout << "Params:\n";
            // for (auto &kv : params)
                // std::cout << kv.first << " = " << kv.second << "\n";
        }
    }
    else
        notFoundHandler();
        //defaulHandler();
}

void Router::setDefaultHandler(std::function<void(std::unordered_map<std::string, std::string>&)> handler)
{
    notFoundHandler();//defaulHandler = handler;
}

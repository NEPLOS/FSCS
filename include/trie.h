

#ifndef MY_TRIE_H
#define MY_TRIE_H


#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include "../include/inc.h"

class Node
{
    public:
    
    std::string data;
    bool isdynamic;
    
    /*
        TODO :
        change vector to map 
        due to the iteration in the vector it will get slower by registering a new route
        
        yeah sure it will use more ram with map but it will be O(1) instead of O(n)


    */
    std::vector<Node*> children;



    //std::function<void(std::unordered_map<std::string, std::string>&)> handler;

    std::unordered_map<Method , std::function<std::string(std::unordered_map<std::string, std::string>&)>> handler;

    Node(std::string&d);
    
    Node* getChild(std::string token, Node*&dynamicNode);
};


class Trie
{
    public:
    Node *head;
    Trie();
    
    void tokenize(std::string &str, std::vector<std::string> &tokens);
    void insertNode(Method method , std::string& path, std::function<std::string(std::unordered_map<std::string, std::string>&)> handler);
    Node *selectedPath(std::string& path, std::unordered_map<std::string, std::string> &params);
    void printTrie(Node* node);
};

#endif

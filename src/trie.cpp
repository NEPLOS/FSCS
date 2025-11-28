
#include "../include/trie.h"
#include <sstream>
#include <iostream>

std::string tabs = "\t";

void Trie::tokenize(std::string &str, std::vector<std::string> &tokens)
{
    std::stringstream ss(str);
    std::string part;
    while (getline(ss, part, '/'))
    {
        if (!part.empty())
            tokens.push_back(part);
    }
}

Node::Node(std::string &d) : data(d)
{
    isdynamic = (!d.empty() && d.front() == '{' && d.back() == '}');
}

Node *Node::getChild(std::string token, Node *&dynamicNode)
{
    dynamicNode = nullptr;

    for (Node *child : children)
    {
        if (!child->isdynamic && child->data == token)
        {
            return child;
        }
    }

    for (Node *child : children)
    {
        if (child->isdynamic)
        {
            if (child->data == token)
            {
                dynamicNode = child;
                return child;
            }
            dynamicNode = child;
        }
    }

    return nullptr;
}

Trie::Trie()
{
    std::string temp = "/";
    head = new Node(temp);
}

void Trie::insertNode(Method method , std::string &path, std::function<std::string(std::unordered_map<std::string, std::string> &)> func)
{
    std::vector<std::string> tokens;
    tokenize(path, tokens);

    Node *current = head;
    for (std::string &tk : tokens)
    {
        Node *next = nullptr;
        Node *dynamicNode = nullptr;
        next = current->getChild(tk, dynamicNode);

        if (!next)
        {
            next = new Node(tk);
            current->children.push_back(next);
        }

        current = next;
    }
    current->handler[method] = func;
}

Node* Trie::selectedPath(std::string &path, std::unordered_map<std::string, std::string> &params)
{
    std::vector<std::string> tokens;
    tokenize(path, tokens);

    Node *current = head;
    for (std::string &tk : tokens)
    {
        Node *dynamicNode = nullptr;
        Node *next = current->getChild(tk, dynamicNode);

        if (!next)
        {
            if (dynamicNode)
            {
                next = dynamicNode;
                params[next->data.substr(1, next->data.size() - 2)] = tk;
            }
            else
            {
                return nullptr;
            }
        }
        current = next;
    }
    return current;
}

void Trie::printTrie(Node *node)
{
    // std::cout << tabs << node->data;
    tabs += "\t";
    for (size_t i = 0; i < node->children.size(); i++)
    {
        std::cout << tabs << node->children[i]->data << '\n';
        printTrie(node->children[i]);
    }
    tabs.pop_back();
}

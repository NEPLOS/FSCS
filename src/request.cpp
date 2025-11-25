
#include "../include/request.h"

void Request::handleStartLine(std::string startLine)
{
    /*
        0 = method
        1 = path
        2 = http-version
    */
    int8_t index = 0; 

    // buffer
    std::string str;
    
    for (int i = 0; i < startLine.size(); i++)
    {
        if (startLine[i] == ' ')
        {
            if (index == 0)
            {
                setMethod(str);
            }
            else if (index == 1)
            {
                path = str;
            }
            
            str.clear();
            index++;
            continue;
        }
        else if (startLine[i] == '\r')
        {
            version = str;
            break;
        }
        
        str.push_back(startLine[i]);

    }
    
}

void Request::parseEachLine(std::string headerLine)
{
    int8_t pos = headerLine.find(": ");
    std::string section = headerLine.substr(0 , pos);
    std::string data = headerLine.substr(pos + 2 , headerLine.size() - 1);

   header[section] = data;


}

void Request::parseBuffer(std::string& buffer)
{
    int16_t num = 0;

    while (true)
    {
        int16_t pos = buffer.find("\r\n");

        if (pos == 0)
        {
            buffer = buffer.substr(pos + 2 , buffer.size() - 1);
            break;
        }
        

        if (pos == std::string::npos)
        {
            break;
        }
        

        std::string section = buffer.substr(0 , pos);
        if (num == 0)
        {
            handleStartLine(buffer);
        }
        else
        {
            parseEachLine(section);
        }
        buffer = buffer.substr(pos + 2 , buffer.size() - 1);
        num++;

    }
    
   // return buffer;

}

void Request::setMethod(std::string method)
{
    if (method == "GET")
    {
        this->method = GET;
    }
    else if (method == "POST")
    {
        this->method = POST;
    }
    else if (method == "PUT")
    {
        this->method = PUT;
    }
    else if (method == "DELETE")
    {
        this->method = DELETE;
    }
    else
    {
        //  invalid HTTP method
        this->method = ERROR;
        std::cout << "wrong request\n";
    }
    
}


void Request::printHeader()
{
    std::cout << "request type (num): " << method << '\n';
    std::cout << "path: " << path << '\n';
    std::cout << "version: " << version << '\n';

    for (auto& line : header)
    {
        std::cout << line.first << ": " << line.second << '\n';
    }

}


Request::~Request()
{

}

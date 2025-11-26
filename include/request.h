
#ifndef MY_HEADER_REQUEST_HANDLER_H
#define MY_HEADER_REQUEST_HANDLER_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "../include/inc.h"

/**
 * Request class handles the parsing and storage of HTTP request headers.
 *
 * @warning This class only deals with the **header portion** of the request.
 *       The body will be handled separately after the headers are fully parsed.
 */
class Request
{
public:
    // all headers info
    std::unordered_map<std::string, std::string> header;

    // method of the request
    Method method = UNKNOWN;

    // the requested path
    std::string path = "/";

    // http version
    std::string version = "";

    // to handle stream data
    bool is_chunked = false;


    /*----------------------------------------------------------------------------------------------------------------------------------*/

    /**
     * @brief parse the request start line
     * @param request only the first line
     */
    void handleStartLine(std::string request);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    /**
     * @brief parses a single HTTP header line but the first one
     * 
     * Example = "section: data"
     */
    void parseEachLine(std::string headerLine);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    // converts a string representation of HTTP method into enum
    void setMethod(std::string method);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    // prints the map
    void printHeader();

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    /**
     *   
     * @param buffer gets the stream buffer
     * @return returns the remaining buffer
     *
     */
    void parseBuffer(std::string &buffer);

    /*----------------------------------------------------------------------------------------------------------------------------------*/

    ~Request();
};

#endif

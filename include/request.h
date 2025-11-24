
#include <iostream>
#include <unordered_map>
#include <string>

// methods
enum Method {
    GET, POST, PUT, DELETE, PATCH, HEAD , UNKNOWN , ERROR
};


/*
 * Request class handles the parsing and storage of HTTP request headers.
 * 
 * @warning This class only deals with the **header portion** of the request.
 *       The body will be handled separately after the headers are fully parsed.
 */
class Request
{
private:

    // all headers info
    std::unordered_map<std::string , std::string > header;

    // method of the request
    Method method = UNKNOWN;

    // the requested path
    std::string path = "/";

    // http version
    std::string version = "";

    // to handle stream data
    bool is_chunked = false;

public:
    /*
        parse the request start line
        @param reqest only the first line
    */
    void handleStartLine(std::string request);
    
    /*
        parses a single http header line but the first one
        format = "section: data"
    */
    void parseEachLine(std::string headerLine);
    
    // converts a string representation of http method into enum
    void setMethod(std::string method);
    
    // prints the map
    void printHeader();
    ~Request();
};

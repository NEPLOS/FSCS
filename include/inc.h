
#ifndef INC_MY_STUFF_H
#define INC_MY_STUFF_H

#include <string>

enum Method
{
    GET,
    POST,
    PUT,
    DELETE,
    PATCH,
    HEAD,
    UNKNOWN,
    ERROR
};

inline std::string MethodToString(Method method)
{
    switch (method)
    {
    case GET:
        return "GET";
    case POST:
        return "POST";
    case DELETE:
        return "DELETE";
    case PATCH:
        return "PATCH";
    case PUT:
        return "PUT";
    default:
        return "UNKNOWN";
    }
}

inline Method StringToMethod(std::string method)
{
    if (method == "GET")
    {
        return GET;
    }
    else if (method == "POST")
    {
        return POST;
    }
    else if (method == "PUT")
    {
        return PUT;
    }
    else if (method == "DELETE")
    {
        return DELETE;
    }

    return ERROR;
}

#endif
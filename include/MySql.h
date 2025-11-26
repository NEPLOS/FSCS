

#ifndef MY_MYSQL_CONNECTION_H
#define MY_MYSQL_CONNECTION_H


#include <string>
#include <iostream>
#include <mysql/mysql.h>
#include <unordered_map>

/*
 *   basic MYSQL handler
 *
 *   @warning 
 *   this class may cause runtime errors, use it by your own risk
 */
class MySQLConnection
{
    public:

    std::string server;
    std::string user;
    std::string password;
    std::string database;

    MYSQL *con;

    /*
     * constructor
     * @param server your server IP address
     * @param user mostly root but yeah....user
     * @param password password from your MYSQL database
     * @param database the name of your database A.K.A schema
     */
    MySQLConnection(std::string server , std::string user , std::string password , std::string databse);

    // setting up the connection to the server
    void mysqlConnectionSetUp();
    
    // executes the query to the server (syntax error in the ```query``` can cause a runtime error)
    MYSQL_RES* mysqlExecuteQuery(std::string query);

    /*
        free results from memory and prevents memory leaks

        @warning
        use is function when you no longer need the result of the query , not using this function can cause 
        memory leaks in your program
    */
    void mysqlFreeResultFromMemory(MYSQL_RES* res);
    

};

#endif

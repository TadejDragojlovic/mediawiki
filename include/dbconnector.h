#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <iostream>
#include <stdlib.h>
#include <variant>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


class DBConnector {
  private:
    sql::Driver* m_driver;
    sql::Connection* m_conn;
  public:
    DBConnector(std::string host, std::string username, std::string password, std::string mysql_schema);
    ~DBConnector();

    sql::Connection* get_conn();
    std::string current_db();
    void execute_prepared_statement(std::string query, std::vector<std::variant<int, double, std::string>> params);
};

#endif
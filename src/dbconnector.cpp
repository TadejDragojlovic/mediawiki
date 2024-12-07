#include "../include/dbconnector.h"

DBConnector::DBConnector(std::string host, std::string username, std::string password, std::string mysql_schema) {
  _driver = get_driver_instance();
  _conn = _driver->connect(host, username, password);
  _conn->setSchema(mysql_schema);
}

DBConnector::~DBConnector() {
  _conn->close();
  delete _conn;
}

std::string DBConnector::current_db() {
  return _conn->getSchema();
}
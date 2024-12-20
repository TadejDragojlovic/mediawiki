#include <iostream>

#include "../include/dbconnector.h"
#include "crow.h"

int main() {
  crow::SimpleApp app;
  DBConnector dbc("localhost", "root", "", "testdb");

  CROW_ROUTE(app, "/")([](){
    return "Hello world";
  });

  app.port(5000).run();
}

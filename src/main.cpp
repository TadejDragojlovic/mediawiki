#include <iostream>

#include "../include/dbconnector.h"
#include "../include/book.h"
#include "crow.h"

int main() {
  crow::SimpleApp app;
  DBConnector dbc("localhost", "root", "", "testdb");

  CROW_ROUTE(app, "/")([](){
    return "Hello world";
  });

  CROW_ROUTE(app, "/add").methods(crow::HTTPMethod::GET, crow::HTTPMethod::POST)
  ([&dbc](const crow::request& req) {
    if(req.method == crow::HTTPMethod::GET) {
      auto page = crow::mustache::load_text("add_book.html");
      return page;
    } else if(req.method == crow::HTTPMethod::POST) {

      Book b(
        req.get_body_params().get("isbn"),
        req.get_body_params().get("title"),
        "none",
        "none"
      );

      // TODO: add response from `add_book()`
      Book::add_book(&dbc, b);

      // placeholder response
      crow::json::wvalue form_req;
      form_req["isbn"] = req.get_body_params().get("isbn");
      form_req["title"] = req.get_body_params().get("title");

      return form_req.dump();
    }

    return std::string("Error.");
  });

  app.port(5000).run();
}

#include "../include/book.h"

Book::Book(string isbn, string title, string author, string collection) 
  : m_BookISBN(isbn), m_BookTitle(title), m_Author(author), m_Collection(collection) {}

string Book::get_isbn() { return m_BookISBN; };
string Book::get_title() { return m_BookTitle; };

// TODO: some kind of validation
void Book::set_isbn(std::string isbn) { m_BookISBN = isbn; };
void Book::set_title(std::string title) { m_BookTitle = title; };

void Book::p() {
  std::cout << "isbn: " << m_BookISBN << "\ntitle: " << m_BookTitle << "\nauthor: " << m_Author << "\ncollection: " << m_Collection << std::endl;
}

void Book::add_book(DBConnector* dbc, Book b) {
  std::cout << "Adding the book.\n";

  sql::PreparedStatement* p_stmt;
  std::string query = "INSERT INTO Book VALUES (?, ?)";

  std::vector<std::variant<int, double, std::string>> params = {
    b.get_isbn(),
    b.get_title(),
  };

  dbc->execute_prepared_statement(query, params);
}
#include "../include/book.h"

Book::Book(string isbn, string title, string author, string collection) 
  : m_BookISBN(isbn), m_BookTitle(title), m_Author(author), m_Collection(collection) {}

void Book::p() {
  std::cout << "isbn: " << m_BookISBN << "\ntitle: " << m_BookTitle << "\nauthor: " << m_Author << "\ncollection: " << m_Collection << std::endl;
}
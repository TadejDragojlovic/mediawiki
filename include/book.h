#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>

using std::string, std::vector;

class Book {
  private:
    string m_BookISBN;
    string m_BookTitle;

    string m_Author;
    string m_Collection;

    // vector<string> m_authors;
    // vector<string> m_categories;

    // TODO: da li treba da napravim i entitet za izdavaca?
    // string m_publisher;


  public:
    Book(string isbn, string title, string author, string collection);
    // ~Book();

    void p();
};

#endif
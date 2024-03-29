// #include <sstream>
// #include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"
#include <string>
#include <sstream>

using namespace std;

Book::Book(std::string category, const std::string name, double price, int qty, std::string isbn, std::string author) : Product(category, name, price, qty) {
    isbn_ = isbn;
    author_ = author;
}

Book::~Book(){}

set<string> Book::keywords() const {
    set<string> keywords_;
    set<string> author_parsed = parseStringToWords(author_);
    set<string> name_parsed = parseStringToWords(name_);
    keywords_.insert(author_parsed.begin(), author_parsed.end());
    keywords_.insert(name_parsed.begin(), name_parsed.end());
    keywords_.insert(isbn_);
    return keywords_;
}

void Book::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}

string Book::displayString() const{
    // return name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.\n";
    stringstream ss;
    ss.precision(2);
    ss << name_ << "\nAuthor: " << author_ << " ISBN: " << isbn_ << "\n";
    ss << showpoint << fixed << price_ << " ";
    ss << qty_ << " left.\n";
    return ss.str();
}
// #include <sstream>
// #include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"
#include <string>

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) : Product(category, name, price, qty) {
    genre_ = genre;
    rating_ = rating;
}

Movie::~Movie(){}

set<string> Movie::keywords() const {
    set<string> keywords_;
    string all_info = genre_ + " " + name_;
    return parseStringToWords(all_info);
}

void Movie::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}

string Movie::displayString() const{
    return name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left.\n";
}
// #include <sstream>
// #include <iomanip>
#include "clothing.h"
#include "product.h"
#include "util.h"
// #include <vector>
#include <string>
// #include <set>

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) : Product(category, name, price, qty) {
    size_ = size;
    brand_ = brand;
}

Clothing::~Clothing(){}

set<string> Clothing::keywords() const {
    set<string> keywords_;
    string all_info = size_ + " " + brand_ + " " + name_;
    return parseStringToWords(all_info);
}

void Clothing::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}

string Clothing::displayString() const{
    return name_ + "\nSize: " + size_ + "\nBrand: " + brand_ + "\nPrice: " + to_string(price_) + " Quantity: " + to_string(qty_) + "\n";
}
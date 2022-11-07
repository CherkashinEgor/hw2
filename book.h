#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "product.h"


class Book : public Product {
    public : 
        Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author);
        
        ~Book();

        virtual std::set<std::string> keywords() const;

        // virtual bool isMatch(std::vector<std::string>& searchTerms) const;

        virtual std::string displayString() const;

        virtual void dump(std::ostream& os) const;
    
    protected:
        std::string isbn_;
        std::string author_;
};
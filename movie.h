#include <string>
#include <set>
#include <vector>
#include "product.h"


class Movie : public Product {
    public : 
        Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
        
        ~Movie();

        virtual std::set<std::string> keywords() const;

        // virtual bool isMatch(std::vector<std::string>& searchTerms) const;

        virtual std::string displayString() const;

        virtual void dump(std::ostream& os) const;
    
    protected:
        std::string genre_;
        std::string rating_;
};
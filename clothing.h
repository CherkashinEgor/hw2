#include <string>
#include <set>
#include <vector>
#include "product.h"

using namespace std;

class Clothing : public Product {
    public : 
        Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
        
        ~Clothing();

        virtual std::set<std::string> keywords() const;

        // virtual bool isMatch(std::vector<std::string>& searchTerms) const;

        virtual std::string displayString() const;

        virtual void dump(std::ostream& os) const;
    
    protected:
        string size_;
        string brand_;
};
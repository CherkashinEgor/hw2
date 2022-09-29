#include "datastore.h"
#include "product.h"
#include "user.h"
#include "util.h"
#include <map>
#include <string>
#include <queue>
#include <set>


class MyDataStore : public DataStore {
    public: 
        MyDataStore();
        ~MyDataStore();

        void addProduct(Product* product);

        void addUser(User* user);

        std::vector<Product*> search(std::vector<std::string>& terms, int type);

        void dump(std::ostream& ofile);

        void addToCart(std::string username, int hit); 

        void printCart(std::string username);

        void buyCart(std::string username);

    protected:
        //String is username and pointer to User object
        std::map<std::string, User*> users;
        //String is product name and pointer to Product object
        std::map<std::string, Product*> products;
        //String is the username and their cart queue
        std::map<std::string, std::queue<Product*>> user_carts;
        //String is the keyword and the associated set of Products 
        std::map<std::string, std::set<Product*>> keywords;
        //Vector of previous search Products
        std::vector<Product*> last_search;
};
#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore(){ }

MyDataStore::~MyDataStore(){
    //Clean up
    map<string, User*>::iterator it_u;
    map<string, Product*>::iterator it_p;
    
    for(it_u = users.begin(); it_u != users.end(); it_u++){
        delete it_u->second;
    } 
    
    for(it_p = products.begin(); it_p != products.end(); it_p++){
        delete it_p->second;
    }
}


void MyDataStore::addUser(User* user){
    //Add user and make an empty cart for them
    users.insert(make_pair(convToLower(user->getName()), user));
    queue<Product*> user_cart;
    user_carts.insert(make_pair(convToLower(user->getName()), user_cart));
}

void MyDataStore::addProduct(Product* product){
    //Add product to products
    // cout << "ADD PRODUCT" << product->getName() << endl; JJJJJJJJ
    products.insert(make_pair(convToLower(product->getName()), product));
    //Get list of keywords 
    set<string> product_keywords = product->keywords();
    map<string, set<Product*>>::iterator keywords_it;
    set<string>::iterator it;
    //Search through existing keywords
    //1. if keyword doesn't exist, add it with product pointer
    //2. if keyword exists, add the product to it
    for(it = product_keywords.begin(); it != product_keywords.end(); it++){
        keywords_it = keywords.find(convToLower(*it));
        if(keywords.count(convToLower(*it)) == 0){
            set<Product*> _keys;
            _keys.insert(product);
            keywords.insert(make_pair(convToLower(*it), _keys));
        } else {
            keywords.find(convToLower(*it))->second.insert(product);
        }
    }
}


vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    vector<Product*> found;
    //If no terms
    if(terms.size() == 0){
        return found;
    }
    //if AND search
    if(type == 0){
        set<Product*> temp;
        //Get list of products from first term and then find intersection with next ones
        if(keywords.count(terms[0]) != 0){
            temp = keywords.find(terms[0])->second;
        }
        if(terms.size() > 1){
            for(unsigned int i = 1; i < terms.size(); i++){
                if(keywords.count(terms[i]) != 0){
                    set<Product*> f = keywords.find(terms[i])->second;
                    temp = setIntersection(temp, f);
                }
            }
        }
        //Convert into vector
        set<Product*>::iterator wow_another_it;
        for(wow_another_it = temp.begin(); wow_another_it != temp.end(); wow_another_it++){
            found.push_back(*wow_another_it);
        }
        last_search = found;
        return found;
    } else {
        // OR search
        // Go through and union each new keyword
        set<Product*> temp;
        for(unsigned int i = 0; i < terms.size(); i++){
            if(keywords.count(terms[i]) != 0){
                set<Product*> f = keywords.find(terms[i])->second;
                // for(auto i : f){
                     // cout << i->getName() << endl; JJJJJJJJ
                // }
                temp = setUnion(temp, f);
            }
        }
        //Convert into vector
        set<Product*>::iterator wow_another_it;
        for(wow_another_it = temp.begin(); wow_another_it != temp.end(); wow_another_it++){
            found.push_back(*wow_another_it);
        }
        last_search = found;
        return found;
    }
}

void MyDataStore::addToCart(string username, int hit){
    username = convToLower(username);
    //Invalid request
    if(hit <= 0 || hit > last_search.size()){
        cout << "Invalid request" << endl;
        return;
    }
    //Invalid username
    if(users.count(username) == 0){
        cout << "Invalid username" << endl;
        return;
    }
    
    //Find user and add to their cart
    queue<Product*> cart = user_carts.find(username)->second;
    cart.push(last_search[hit-1]);
    user_carts.find(username)->second = cart;
    // cout << "Item " << hit << endl; JJJJJJJ
    // cout << last_search[hit-1]->displayString();
}

void MyDataStore::printCart(string username){
    //Printing
    username = convToLower(username);
    if(users.count(username) == 0){
        cout << "Invalid username" << endl;
        return;
    }
    queue<Product*> print(user_carts.find(username)->second);
    // cout << endl << username << "'s Cart: " << endl;
    int count = 1;
    while(!print.empty()){
        cout << "Item " << count << endl;
        cout << print.front()->displayString() << endl;
        print.pop();
        count += 1;
    }
}

void MyDataStore::buyCart(string username){
    username = convToLower(username);
    //Check for invalid issues
    if(users.count(username) == 0){
        cout << "Invalid username" << endl;
        return;
    }
    User* user = users.find(username)->second;
    queue<Product*> q = user_carts.find(username)->second;
    queue<Product*> didnt_buy;
    //Go through and try to buy each item
    while(!q.empty()){
        Product* p = q.front();
        int cur_bal = user->getBalance();
        //If u can't buy it for whatever reason
        if(p->getPrice() > cur_bal || p->getQty() == 0){
            didnt_buy.push(p);
            q.pop();
            continue;
        } else {
            user->deductAmount(p->getPrice());
            p->subtractQty(1);
            q.pop();
        }
    }
    
    user_carts.find(username)->second = didnt_buy;
    
}


void MyDataStore::dump(ostream& ofile){
    ofile << "<products>\n";
    map<string, Product*>::iterator it;
    for(it = products.begin(); it != products.end(); it++){
        it->second->dump(ofile);
    }
    ofile << "</products>\n";

    ofile << "<users>\n";
    map<string, User*>::iterator user_it;
    for(user_it = users.begin(); user_it != users.end(); user_it++){
        user_it->second->dump(ofile);
    }
    ofile << "</users>\n";
}


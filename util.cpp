#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    //add case insensitivity
    set<string> my_set;
    string word;
    for(int i = 0; i < rawWords.length(); i++){
        if(rawWords[i] == '-'){
            word.push_back(rawWords[i]);
            // cout << "Word: " << word << endl;
        } else {
            if(ispunct(rawWords[i]) || rawWords[i] == ' '){
                if(word.length() >= 2){
                    my_set.insert(word);
                    word = "";
                } else {
                    word = "";
                }
            } else {
                word.push_back(rawWords[i]);
                // cout << "Word: " << word << endl;
            }
        }
    }

    if(word.length() >= 2){
        my_set.insert(word);
    }

    // for (auto it = my_set.begin(); it != my_set.end(); ++it)
    //     cout << "e " << *it << endl;
    return my_set;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

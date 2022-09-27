#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    //Optimize later
    typename std::set<T>::iterator it1;
    typename std::set<T>::iterator it2;
    std::set<T> intersection;

    for(it1 = s1.begin(); it1 != s1.end(); it1++){
        for(it2 = s2.begin(); it2 != s2.end(); it2++){
            if(*it1 == *it2){
                intersection.insert(*it1);
            }
        }
    }

    return intersection;
    
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    //Just insert two sets
    typename std::set<T> union_set;
    union_set.insert(s1.begin(), s1.end());
    union_set.insert(s2.begin(), s2.end());
    return union_set;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif

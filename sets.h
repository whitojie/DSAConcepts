#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

// SETS

/*
    Sets are a type of associative container
    in which each element has to be unique,
    because the value of the element
    identifies it. Sets tell us whether an
    element is present or not.
*/

class Set{
private:
    set<char> s1;
public:
    void display(set<char>& chars);
    void insertElement(set<char>& chars, char c);
    void eraseElement(set<char>& chars, char c);
    void searchErase(string s, set<char> exists);
};

void Set::display(set<char>& chars){
    for (auto iter = chars.begin(); iter != chars.end(); iter++){
        cout << *iter << endl;
    }
}

void Set::insertElement(set<char>& chars, char c) {
    auto result = chars.insert(c); // Insert returns a pair (iterator, success_flag)
    if (result.second) {
        cout << "Inserted: " << c << endl;
    } else {
        cout << c << " is already in the set." << endl;
    }
}

void Set::eraseElement(set<char>& chars, char c) {
    size_t count = chars.erase(c); // erase returns the number of elements removed
    if (count > 0) {
        cout << "Erased: " << c << endl;
    } else {
        cout << c << " was not found in the set." << endl;
    }
}

void Set::searchErase(string s, set<char> exists) {
    for (int i = 0; i < s.length(); i++) {
        char letter = s[i];
        exists.insert(letter);
    }
    for (auto iter = exists.begin(); iter != exists.end(); iter++){
        cout << *iter << endl;
    }
}

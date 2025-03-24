#ifndef _MY_STRING_
#define _MY_STRING_

#include <iostream>
#include <cmath>

#define UVELICHCONST 1.5

// necessary includes
// see: https://en.cppreference.com/w/cpp/string/basic_string

class MyString {
private:
    char* str = nullptr;
    unsigned int sizeStr = 0;
    unsigned int capacity = 0;
public:
    // constructors
    MyString() {};
    MyString(unsigned int count, char ch);
    MyString(const char* string);  // copy
    
    // RULE OF THREE methods
    MyString(const MyString& copy);  // copy constructor
    ~MyString();  // destroy object
    MyString& operator=(const MyString& v);
    
    // element access without bound checking
    char& operator[](unsigned int index);
    char operator[](unsigned int index) const;
    // element access with bound checking
    char& at(unsigned int index);
    char at(unsigned int index) const;
    
    // raw data access
    const char* c_str() const;
    char* data();
    const char* data() const;
    
    // auxiliary
    bool empty() const;
    unsigned int size() const;  // O(1)
    unsigned int length() const;  // O(1)
    void print() const;
    

    // modifiers
    void clear();
    void resize(unsigned int count);
    void realloc(unsigned int count); // realloc != resize; realloc (sizeStr -> sizeStr; capacity -> count)
    unsigned int insert(unsigned int pos, char ch);  // aad, insert(2, 'b') => aabd, return pos
    unsigned int insert(unsigned int pos, const MyString& substr); // aad, insert(2, "bc") => aabcd
    unsigned int erase(unsigned int pos);  // aabd, erase(2) => aad
    unsigned int erase(unsigned int pos, unsigned int count);  // aabd, erase(2, 2) => aa
    void push_back(char ch);  // insert to the end
    void pop_back();  // erase from the end
    // concatenation, "aaa" + "bb" => "aaabb"
    MyString operator+(const MyString& string);
    MyString& operator+=(const MyString& string);
    
    // search
    unsigned int find(const MyString& substr, unsigned int pos = 0);  // MyString("aaab").find("ab") => 2
    // O(nm) => O(n+m), Рабина-Карпа, КМП
    // compare, lexicograph. order
    int compare(const MyString& string) const;
    bool operator==(const MyString& string) const;
    bool operator!=(const MyString& string) const;
    bool operator<(const MyString& string) const;
    bool operator>(const MyString& string) const;
    bool operator<=(const MyString& string) const;
    bool operator>=(const MyString& string) const;
};
#endif
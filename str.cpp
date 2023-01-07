#include "str.h"
#include <cstring>

str::str() : _n(0), _buf(0)
{}

str::str(int n) : _n(n)
{
    _buf = new char[_n];
}

str::str(char ch) : _n(1)
{
    _buf = new char[_n];
    _buf[0] = ch;
}

str::str(const char* c_str)
{
    _n = strlen(c_str);
    _buf = new char[_n];
    for (int i=0; i<_n; ++i) _buf[i]=c_str[i];
}

str::~str()
{
    if (_buf) delete [] _buf;
}

ostream& operator<<(ostream& os, const str& s)
{
    if (!s.is_empty()) {
        for (int i=0; i<s.length(); ++i) {
        cout << s[i];
        }
    }
    else cout << "[null str]";
    
    return os;
}

istream& operator>>(istream& is, str& s)
{
    char ch;
    do {
        ch = is.get();
        if (ch == ' ' || ch == '\n') break;
        s = s + ch;
    } while(true);

    return is;
}

// 1. TODO - assignment operator
const str& str::operator=(const str& s)
{
    if (this!= &s) // string s must not be empty
    {
        _n = s._n; // let _n = size of string s
        char* _buf = new char[_n]; // create new buffer with size _n

        for (int i=0; i<_n; i++)
        {
            _buf[i] = s[i]; // put each character of string s to buffer _buf
        }
    }
    return *this; // return the string buffer
}

// 2. TODO - concatenation operator
str operator+(const str& a, const str& b)
{
    str line(a._n + b._n); 

    for (int i=0; i<a._n; i++)
    {
        line._buf[i] = a._buf[i]; // put contents of 1st string *a* to to the buffer _buf
    }

    for (int j=0; j<b._n; j++)
    {
        line._buf[j + a._n] = b._buf[j]; // continue to put contents of 2nd string *b* to to the buffer _buf (which already had string a)
    }
    return line; // return the concatenated new string of a & b
}

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TableCipher
{
public:
    TableCipher(const int &skey);
    string encrypt(const string &open_text);
    string decrypt(const string &cipher_text);
    TableCipher()=delete;
    bool isRussianChar(wchar_t c);
private:
    int key;
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
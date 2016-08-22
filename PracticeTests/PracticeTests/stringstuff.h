#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;
void printRecurse(int n);

// reverse string per char
string recur(string s);

// reverse string word by word
vector<string> reverseString(vector<string> vec);

// reverse string word by word not recursive
vector<string> reverseString(vector<string> vec, bool b);

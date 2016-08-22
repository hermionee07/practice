#include <vector>
#include <string>
#include <iostream>

using namespace std;
void printRecurse(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printRecurse(n - 1);

    return;

}
// reverse string per char
string recur(string s)
{
    if (s.length() == 1)
        return s;
    string temp = recur(s.substr(1, s.length()));
    return temp + s[0];
}


// reverse string word by word
vector<string> reverseString(vector<string> vec)
{
    if (vec.size() == 1)
        return vec;
    vector<string> t = reverseString(vector<string>(vec.begin() + 1, vec.end()));
    t.push_back(vec[0]);
    return t;
}
// reverse string word by word not recursive
vector<string> reverseString(vector<string> vec, bool b)
{
    return vector<string>();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool myfunction(string i, string j)
{
    return (i.length() < j.length());
}

int main(void)
{
    string myints[] = {"hello", "world", "i", "love"};
    vector<string> myvec(myints, myints + 4);

    sort(myvec.begin(), myvec.end(), myfunction);

    for (vector<string>::iterator it = myvec.begin(); it != myvec.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
    return 0;
}

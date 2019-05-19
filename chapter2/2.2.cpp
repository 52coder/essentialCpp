#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

void pen(vector<int> &ivec, int n)
{
    if (n <= 0 || n >= 1024) {
        return;
    }
    for (int i = 0; i < n; i++) {
        ivec.push_back(i * (3 * i - 1) / 2);
    }
}

template <typename T>
void print(const vector<T> &vec, const string &type)
{
    for (int i = 0; i < vec.size(); i++) {
       cout << vec[i] << ' ';
    }
    cout << endl;
}

int main(void)
{
    vector<int> ivec;
    pen(ivec, 6);
    print(ivec, "int");

    vector<string> svec;
    svec.push_back("hello");
    svec.push_back("world");
    svec.push_back("i");
    svec.push_back("love");
    print(svec, "string");

    vector<float> fvec;
    fvec.push_back(1.1);
    fvec.push_back(1.2);
    fvec.push_back(1.3);
    fvec.push_back(1.4);
    fvec.push_back(1.5);
    fvec.push_back(1.6);
    print(fvec, "float");

    return 0;
}

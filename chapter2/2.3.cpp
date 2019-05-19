#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int isOk(int n)
{
    return (0 < n && n < 1024);
}
void pen(vector<int> &ivec, int n)
{
    if (!isOk(n)) {
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

    return 0;
}

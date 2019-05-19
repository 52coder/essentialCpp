#include <iostream>
#include <string>
using namespace std;

template <typename T>
T *Find(T *first, T *last, const T &val)
{
    if (!first || !last) {
        return 0;
    }
    for (; first != last; first++) {
        if (*first == val) {
            return first;
        }
    }
    return 0;
}

int main(void)
{
    int ia[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    double da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    string sa[4] = {"hello", "world", "i", "love"};

    int *pi = Find(ia, ia + 8, ia[3]);
    double *pd = Find(da, da + 6, da[3]);
    string *ps = Find(sa, sa + 4, sa[3]);

    if (pi) {
        cout << *pi << endl;
    }
    if (pd) {
        cout << *pd << endl;
    }
    if (ps) {
        cout << *ps << endl;
    }

    return 0;
}

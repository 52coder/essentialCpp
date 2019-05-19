#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename IteratorType, typename elemType>
IteratorType Find(IteratorType first, IteratorType last, const elemType &value)
{
    for (; first != last; ++first) {
        if (value == *first) {
            return first;
        }
    }
    return last;
}

int main(void)
{
    const int asize = 8;
    int ia[asize] = {1, 1, 2, 3, 5, 8, 13, 21};

    vector<int> ivec(ia, ia + asize);
    list<int> ilist(ia, ia + asize);

    int *pia = Find(ia, ia + asize, 1024);
    if (pia != ia + asize) {
        cout << *pia << endl;
    }
    vector<int>::iterator it;
    it = Find(ivec.begin(), ivec.end(), 8);
    if (it != ivec.end()) {
        cout << *it << endl;
    }
    list<int>::iterator iter;
    iter = Find(ilist.begin(), ilist.end(), 8);
    if (iter != ilist.end()) {
        cout << *iter << endl;
    }

    return 0;
}

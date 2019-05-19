#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename InputIterator, typename OutputIterator,
    typename ElemType, typename Comp>
OutputIterator
Filter(InputIterator first, InputIterator last,
        OutputIterator at, const ElemType &val, Comp pred)
{
    while ((first = find_if(first, last, bind2nd(pred, val))) != last) {
        cout << "found value: " << *first << endl;
        *at++ = *first++;
    }
    return at;
}

int main(void)
{
    const int elem_size = 8;

    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);

    vector<int> ivec2;

    cout << "filtering integer vector for values greater than 8\n";
    Filter(ivec.begin(), ivec.end(), back_inserter(ivec2), elem_size, greater<int>());

    return 0;
}

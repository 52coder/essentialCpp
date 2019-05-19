#include "triangular_iterator.h"

int main(void)
{
    Triangular tr(32);
    cout << tr << "--sum of elements:" << tr.sum() << endl;

    Triangular tr2(4, 3);
    cout << tr2 << "--sum of elements:" << tr2.sum() << endl;

    Triangular tr3(4, 8);
    cout << tr3 << "--sum of elements:" << tr3.sum() << endl;

    Triangular tr4(20, 12);
    Triangular::iterator it = tr4.begin();
    Triangular::iterator end_it = tr4.end();
    cout << "triangular series of " << tr4.length() << " elements\n";
    cout << tr4 << endl;
    while (it != end_it) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    return 0;
}

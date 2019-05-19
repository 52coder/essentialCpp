#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Triangular{
public:
    Triangular(int length = 1, int beg_pos = 1)
    {
        _length = length;
        _beg_pos = beg_pos;
        for (int i = beg_pos; i < beg_pos + length; i++) {
            sivec.push_back(i * (i + 1) / 2);
        }
    }
    int beg_pos() const
    {
        return _beg_pos;
    }
    int length() const
    {
        return _length;
    }
    void show() const
    {
        for (int i = 0; i < sivec.size(); i++) {
            cout << sivec[i] << " ";
        }
        cout << endl;
    }
    int sum() const
    {
        int sum = 0;
        for (int i = 0; i < sivec.size(); i++) {
            sum += sivec[i];
        }
        return sum;
    }
private:
    int _length;
    int _beg_pos;

    vector<int> sivec;
};

ostream &operator<<(ostream &os, Triangular &rhs)
{
    os << "(" << rhs.beg_pos() << "," << rhs.length() << ")";
    rhs.show();

    return os;
}

int main(void)
{
    Triangular tr(4);
    cout << tr << "--sum of elements:" << tr.sum() << endl;
    Triangular tr2(4, 3);
    cout << tr2 << "--sum of elements:" << tr2.sum() << endl;
    Triangular tr3(4, 8);
    cout << tr3 << "--sum of elements:" << tr3.sum() << endl;

    return 0;
}

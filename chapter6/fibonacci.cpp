#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<int len, int beg_pos>
class num_sequence{
public:
    virtual ~num_sequence(){};
    int elem(int pos) const;
    static int max_elems() {return _max_elems;}
    ostream &print(ostream &os = cout) const;
protected:
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;

    num_sequence(vector<int> *pe) : _pelems(pe) {}
    static const int _max_elems = 1024;
    vector<int> *_pelems;
};

template <int len, int beg_pos> ostream &
operator<<(ostream &os, const num_sequence<len, beg_pos> &ns)
{
    return ns.print(os);
}

template <int len, int beg_pos>
int num_sequence<len, beg_pos>::
elem(int pos) const
{
    if (!check_integrity(pos, _pelems->size())) {
        return 0;
    }
    return (*_pelems)[pos - 1];
}

template <int length, int beg_pos>
bool num_sequence<length, beg_pos>::
check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > max_elems()) {
        cerr << ":!!invalid position:" << pos
            << " cannot honor request\n";
        return false;
    }
    if (pos > size) gen_elems(pos);
    return true;
}

template <int length, int beg_pos>
ostream &num_sequence<length, beg_pos>::
print(ostream &os) const
{
    int elem_pos = beg_pos - 1;
    int end_pos = elem_pos + length;

    if (!check_integrity(end_pos, _pelems->size())) {
            return os;
    }
    os << "("
        << beg_pos << ","
        << length << ")";
    while (elem_pos < end_pos) {
        os << (*_pelems)[elem_pos++] << ' ';
    }
    return os;
}

template<int length, int beg_pos = 1>
class Fibonacci:public num_sequence<length, beg_pos>{
public:
    Fibonacci() : num_sequence<length, beg_pos>(&_elems){}
protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};

template<int length, int beg_pos>
vector<int> Fibonacci<length, beg_pos>::_elems;

template <int length, int beg_pos>
void Fibonacci<length, beg_pos>::
gen_elems(int pos) const
{
    if (pos <= 0 || pos > num_sequence<length, beg_pos>::max_elems()) {
        return;
    }
    if (_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    if (_elems.size() <= pos) {
        int ix = _elems.size();
        int n_2 = _elems[ix - 2],
            n_1 = _elems[ix - 1];
        int elem;
        for (; ix <= pos; ++ix) {
            elem = n_2 + n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}

int main(void)
{
    Fibonacci<8> fib1;
    Fibonacci<8, 8> fib2;
    Fibonacci<12, 8> fib3;

    cout << "fib1:" << fib1 << endl;
    cout << "fib2:" << fib2 << endl;
    cout << "fib3:" << fib3 << endl;

    return 0;
}

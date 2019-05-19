#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Triangular_iterator{
public:
    Triangular_iterator(int index):_index(index){}
    bool operator==(const Triangular_iterator&) const;
    bool operator!=(const Triangular_iterator&) const;
    int operator*() const;
    Triangular_iterator& operator++();
    Triangular_iterator operator++(int);
private:
    void check_integrity() const;
    int _index;
};

class Triangular{
    friend Triangular_iterator;
public:
    Triangular(int length = 1, int beg_pos = 1)
    {
        _length = length;
        _beg_pos = beg_pos;
        _elems.clear();
        for (int i = beg_pos; i < beg_pos + length; i++) {
            _elems.push_back(i * (i + 1) / 2);
        }
    }
    typedef Triangular_iterator iterator;
    Triangular_iterator begin()
    {
        return Triangular_iterator(0);
    }
    Triangular_iterator end()
    {
        return Triangular_iterator(_length);
    }
    int beg_pos() const
    {
        return _beg_pos;
    }
    int length() const
    {
        return _length;
    }
    static void show()
    {
        for (int i = 0; i < _elems.size(); i++) {
            cout << _elems[i] << " ";
        }
    }
    static int sum()
    {
        int sum = 0;
        for (int i = 0; i < _elems.size(); i++) {
            sum += _elems[i];
        }
        return sum;
    }
    static void gen_elements(int index)
    {
        for (int i = _elems.size(); i < index; i++) {
            _elems.push_back(i * (i + 1) / 2);
        }
    }
private:
    int _length;
    int _beg_pos;
    static vector<int> _elems;
};
vector<int> Triangular::_elems;

ostream& operator<<(ostream &os, Triangular &rhs)
{
    os << "(" << rhs.beg_pos() << "," << rhs.length() << ") ";
    rhs.show();

    return os;
}

inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const
{
    return _index == rhs._index;
}
inline bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const
{
    return !(*this == rhs);
}
inline int Triangular_iterator::operator*() const
{
    check_integrity();
    return Triangular::_elems[_index];
}
inline void Triangular_iterator::check_integrity() const
{
    if (_index >= Triangular::_elems.size()) {
        Triangular::gen_elements(_index);
    }
}
inline Triangular_iterator &Triangular_iterator::operator++()
{
    ++_index;
    check_integrity();
    return *this;
}
inline Triangular_iterator Triangular_iterator::operator++(int)
{
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}


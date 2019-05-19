#include <iostream>
#include <vector>
using namespace std;

class LessThan{
public:
    LessThan(int val) : _val(val){}
    int comp_val() const {return _val;}
    void comp_val(int nval) {_val = nval;}

    bool operator()(int value) const
    {
        return value < _val;
    }
private:
    int _val;
};

int count_less_than(const vector<int> &vec, int comp)
{
    LessThan lt(comp);
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (lt(vec[i])) {
            ++count;
        }
    }
    return count;
}

int main(void)
{
    vector<int> ivec;
    for (int i = 0; i < 20; i++) {
        ivec.push_back(i);
    }
    cout << count_less_than(ivec, 10) << endl;

    return 0;
}

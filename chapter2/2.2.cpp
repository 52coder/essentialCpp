#include <iostream>
#include <vector>
#include <string>
using namespace std;

void display_elems(const vector<int> &vec,const string &title,ostream &os=cout);

bool calc_elements(vector<int> &ivec, int pos)
{
    if (pos <= 0 || pos > 512) {
        cerr <<"Sorry.Invalid position: " << pos <<endl;
        return false;
    }
    for (int i = ivec.size() + 1; i <= pos; i++) {
        ivec.push_back(i * (3 * i - 1) / 2);
    }
}

void display_elems(const vector<int> &vec, const string &title,ostream &os)
{
    os << '\n' << title << "\n\t";
    for (int i = 0; i < vec.size(); i++) {
       os << vec[i] << ' ';
    }
    cout << endl;
}

int main(void)
{
    vector<int> ivec;
    calc_elements(ivec, 6);
    display_elems(ivec, "int");


    return 0;
}

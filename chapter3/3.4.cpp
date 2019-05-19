#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    istream_iterator<int> in(cin);
    istream_iterator<int> eof;
    ofstream file1("data1.txt");
    ofstream file2("data2.txt");
    ostream_iterator<int> out1(file1);
    ostream_iterator<int> out2(file2);
    if (!file1 || !file2) {
        cerr << "open file error!\n";
        return -1;
    }
    vector<int> ivec;
    copy(in, eof, back_inserter(ivec));
    for (int i = 0; i < ivec.size(); i++) {
        if (ivec[i] % 2) {
            file1 << ivec[i] << ' ';
        } else {
            file2 << ivec[i] << ' ';
        }
    }
    file1.close();
    file2.close();

    return 0;
}

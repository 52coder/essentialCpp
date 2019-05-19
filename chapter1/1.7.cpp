#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(void)
{
    ofstream outfile("data.txt");
    string word;
    while (cin >> word) {
        outfile << word << ' ';
    }
    outfile.close();

    ifstream infile("data.txt");
    vector<string> vec;
    while (infile) {
        infile >> word;
        vec.push_back(word);
    }
    infile.close();

    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

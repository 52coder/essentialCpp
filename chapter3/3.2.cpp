#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

bool Large(string str1,string str2)
{
    return (str1.length() <= str2.length());
}

int main(void)
{
    ifstream input_file("data.txt");
    if (!input_file) {
        cerr << "open data.txt error!\n";
        return -1;
    }

    vector<string> svec;
    string arr[] = {"a", "an", "or", "the", "and", "but"};
    set<string> setwords(arr, arr + 6);
    string word;
    while (input_file >> word) {
        if (0 == setwords.count(word)) {
            svec.push_back(word);
        }
    }
    input_file.close();
    sort(svec.begin(), svec.end(), Large);

    vector<string>::iterator beg = svec.begin();
    for (; beg != svec.end(); beg++) {
        cout << *beg << ' ';
    }
    cout << endl;

    return 0;
}

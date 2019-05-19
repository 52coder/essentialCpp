#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    ifstream inputfile("data.txt");
    if (!inputfile) {
        cerr << "open data.txt error!\n";
        return -1;
    }

    map<string, int> ismap;
    string word;
    string strword[] = {"a", "an", "or", "the", "and", "but"};
    set<string> setwords(strword, strword + 6);

    while (inputfile >> word) {
        if (0 == setwords.count(word)) {
            ismap[word]++;
        }
    }
    inputfile.close();

    map<string, int>::iterator beg = ismap.begin();
    for (; beg != ismap.end(); beg++) {
        cout << beg->first << ":" << beg->second << endl;
    }

    return 0;
}

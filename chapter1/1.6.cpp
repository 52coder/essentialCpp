#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(void)
{
    vector<int> ivec;
    int num = 0;
    while (cin >> num) {
        ivec.push_back(num);
    }

    int i = 0;
    int sum = 0;
    for (i = 0; i < ivec.size(); i++) {
        sum += ivec[i];
    }
    cout << "sum is: " << sum << " and average is: " << sum * 1.0 / ivec.size() << endl;

    return 0;
}

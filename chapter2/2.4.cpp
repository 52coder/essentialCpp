#include <iostream>
#include <vector>
#include <string>
using namespace std;

int isOk(int n)
{
    return (0 < n && n < 1024);
}
vector<int> *pen(int n)
{
    if (!isOk(n)) {
        return NULL;
    }
    static vector<int> ivec;
    for (int i = ivec.size() + 1; i <= n; i++) {
        ivec.push_back(i * (3 * i - 1) / 2);
    }

    return &ivec;
}
int pen_elem(int index)
{
    vector<int> *pvec = pen(index);
    if (pvec == NULL) {
        return -1;
    }
    return (*pvec)[index - 1];
}

int main(void)
{
    cout << pen_elem(5) << endl;
    cout << pen_elem(9) << endl;
    cout << pen_elem(1) << endl;
    cout << pen_elem(11111) << endl;
    cout << pen_elem(99) << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string user_name;
    string user_content;
    cout << "please enter your name:";
    cin >> user_name;
    while (user_name.length() < 2) {
        cerr << "name length should be large than 2\n";
        cin >> user_name;
    }
    cout << "please enter your content:";
    cin >> user_content;

    cout << user_name << " say: " << user_content << endl;

    return 0;
}

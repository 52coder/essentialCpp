#include <iostream>
#include <string>
using namespace std;

int my_main(void)
{
    string user_name;
    cout << "Please enter your first name: ";
    cin >> user_name;
    cout << "\nHello, " + user_name + "... and goodbye!\n";

    return 0;
}

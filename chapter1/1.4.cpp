#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string first_name, second_name;
    cout << "Please enter your first name and second name: ";
    cin >> first_name >> second_name;
    cout << "Hello " << first_name << " " << second_name << "... and goodbye!\n";

    return 0;
}

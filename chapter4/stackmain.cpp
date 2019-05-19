#include "stack.h"

int main(void)
{
    Stack stack;
    string arr[] = {"hello", "world", "i", "love"};
    for (int i = 0; i < 4; i++) {
        stack.push(arr[i]);
    }
    string elem;
    stack.pop(elem);
    cout << elem << endl;
    if (stack.empty()) {
        cout << "empty\n";
    } else {
        cout << "not empty\n";
    }
    if (stack.full()) {
        cout << "full\n";
    } else {
        cout << "not full\n";
    }
    if (stack.find("hello")) {
        cout << "we find hello" << endl;
    } else {
        cout << "we cannot find hello" << endl;
    }
    cout << stack.count("world") << endl;

    return 0;
}

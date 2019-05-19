#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Stack {
public:
    bool    push(const string&);
    bool    pop(string &elem);
    bool    peek(string &elem);

    bool    empty();
    bool    full();

    bool    find(const string&);
    int     count(const string&);

    int     size() {return _stack.size();}
private:
    vector<string> _stack;
};

bool Stack::push(const string &elem)
{
    if (full()) {
        return false;
    }
    _stack.push_back(elem);
    return true;
}

bool Stack::pop(string &elem)
{
    if (empty()) {
        return false;
    }
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string &elem)
{
    if (empty()) {
        return false;
    }
    elem = _stack.back();
    return true;
}

bool Stack::empty()
{
    return _stack.empty();
}

bool Stack::full()
{
    return _stack.size() == _stack.max_size();
}

bool Stack::find(const string &elem)
{
    return ::find(_stack.begin(), _stack.end(), elem) != _stack.end();
}

int Stack::count(const string &elem)
{
    return ::count(_stack.begin(), _stack.end(), elem);
}

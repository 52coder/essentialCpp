#include <iostream>
#include <list>
using namespace std;

class Stack{
protected:
    virtual ~Stack() {}

    virtual int pop() = 0;
    virtual void push(int val) = 0;
    virtual int size() const = 0;
    virtual int empty() const = 0;
    virtual int full() const = 0;
    virtual int peek() const = 0;
    virtual void print() = 0;
};

class LIFO_Stack : public Stack {
public:
    LIFO_Stack(list<int> &elems):
        _elems(elems)
    {}
    LIFO_Stack()
    {}
    virtual int pop()
    {
        if (empty()) {
            cerr << "LIFO_Stack is empty()\n";
            return -1;
        }
        int elem = _elems.front();
        _elems.pop_front();
        return elem;
    }
    virtual void push(int val)
    {
        if (full()) {
            cerr << "LIFO_Stack is full()\n";
            return;
        }
        _elems.push_back(val);
    }
    virtual int size() const
    {
        return _elems.size();
    }
    virtual int empty() const
    {
        return _elems.empty();
    }
    virtual int full() const
    {
        return _elems.size() == _elems.max_size();
    }
    virtual int peek() const
    {
        return _elems.front();
    }
    virtual void print()
    {
        list<int>::iterator beg = _elems.begin();
        for (; beg != _elems.end(); beg++) {
            cout << *beg << " ";
        }
        cout << endl;
    }

private:
    list<int> _elems;
};

int main(void)
{
    LIFO_Stack lifo;
    for (int i = 0; i < 10; i++) {
        lifo.push(i);
    }
    lifo.print();

    cout << lifo.pop() << endl;
    cout << lifo.pop() << endl;
    lifo.print();

    cout << "lifo size:" << lifo.size() << endl;

    return 0;
}

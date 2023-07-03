#include <iostream>

template<class T>
class Stack {
private:
    int _MaxSize = 0;
    int _Size = 0;
    int st_size = 0;
    T *_Elements;
public:
    Stack(int msize) {
        _MaxSize = msize;
        try {
            _Elements = new T[msize];
        }
        catch (const std::bad_alloc) {
            std::cerr << "Constructor ERROR: too big size";
        }
    }

    Stack(int msize, int size, T item) {  // в этом конструкторе больше смысла, т.к. мы чем-то забиваем массив
        try {
            _MaxSize = msize;
            _Elements = new T[msize];
            for (int i = 0; i < size; i++)
                _Elements[i] = item;
            _Size = size;
        }
        catch (const std::bad_alloc) {
            std::cerr << "Constructor ERROR: too big size";
        }
    }

    int Size() {
        return _Size;
    }

    bool Empty() {
        return _Size != 0;
    }

    bool Push(T NewElement) {
        if (_Size < _MaxSize) {
            _Elements[_Size] = NewElement;
            ++_Size;
        } else {
            throw std::overflow_error("Push ERROR: stack is full");
        }
    }

    T Pop() {
        if (_Size != 0) {
            T tmp = _Elements[0];
            for (int i = 0; i < _MaxSize - 1; ++i) {
                _Elements[i] = _Elements[i + 1];
            }
            --_Size;
            return tmp;
        } else {
            throw std::out_of_range("Pop ERROR: stack is empty");
        }
    }

    T &Top() {
        if (_Size != 0) {
            return _Elements[_Size - 1];
        } else {
            throw std::logic_error("Top ERROR: stack is empty");
        }
    }

    ~Stack() {
        delete[] _Elements;
    }
};

int main() {
    Stack<int> stack(11);
    std::cout << stack.Empty() << std::endl;  // empty()
    //stack.top();
    for (int i = 0; i < 11; ++i) {
        stack.Push(100 + i);
    }
    std::cout << stack.Empty() << std::endl;
    std::cout << "Size of stack: " << stack.Size() << std::endl;    /// size()

    std::cout << "delete item: " << stack.Top() << std::endl;    // top()
    stack.Pop();    // pop()
    std::cout << "Size changed " << stack.Size() << ", and top element too: " << stack.Top() << std::endl;
    Stack<std::string> stack1(15, 10, "job");
    int n = stack1.Size();
    for (int i = 0; i < n; i++) {
        std::cout << stack1.Pop() << std::endl;
    }
    return 0;
}

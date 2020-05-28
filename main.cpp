#include <iostream>
#include <time.h>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
class Math
{
private:
    T* arr_stack[100];
    int nn;
    int n_stack;
public:
    Math();
    void push_stack(T temp);
    void pop_stack();
    int sizeof_stack();
    void print_stack();
};


template<typename T>
Math<T>::Math()
{
    for (int i = 0; i < nn; i++)
    {
        arr_stack[i] = NULL;
    }
    n_stack = 0;
    nn = 100;
}

template<typename T>
void Math<T>::push_stack(T temp)
{
    if (n_stack == nn)
    {
        cout << "Стек переповнений";
    }
    else
    {
        T* ptemp = (T*)malloc(sizeof(T));
        *ptemp = temp;
        arr_stack[n_stack] = ptemp;
        n_stack++;
    }
}

template<typename T>
void Math<T>::pop_stack()
{
    arr_stack[n_stack] = NULL;
    n_stack--;
}

template<typename T>
int Math<T>::sizeof_stack()
{
    return n_stack;
}

template<typename T>
void Math<T>::print_stack()
{
    for (int i = 0; i < n_stack; i++)
    {
        cout << *arr_stack[i];
        cout << "     ";
    }
    cout << "\n";
}


template <typename T, typename U>
class Iterator {
public:
    typedef typename std::vector<T>::iterator iter_type;
    Iterator(U* p_data, bool reverse = false) : m_p_data_(p_data) {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void First() {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void Next() {
        m_it_++;
    }

    bool IsDone() {
        return (m_it_ == m_p_data_->m_data_.end());
    }

    iter_type Current() {
        return m_it_;
    }

private:
    U* m_p_data_;
    iter_type m_it_;
};




template <class T>
class Container {
    friend class Iterator<T, Container>;

public:
    void Add(T a) {
        m_data_.push_back(a);
    }

    Iterator<T, Container>* CreateIterator() {
        return new Iterator<T, Container>(this);
    }

private:
    std::vector<T> m_data_;
};



int main() {
    Math<int> obj1;
    obj1.push_stack(5);
    obj1.push_stack(3);
    obj1.push_stack(1);
    obj1.push_stack(3);
    obj1.push_stack(9);
    obj1.print_stack();

    Math<int> obj2;
    obj2.push_stack(5);

    Math<int> obj3;
    obj3.push_stack(4);
    obj3.push_stack(7);
    obj3.push_stack(12);
    obj3.push_stack(11);

    Container<Math<int>> cont;
    cont.Add(obj1);
    cont.Add(obj2);
    cont.Add(obj3);

    std::cout << "________________Iterator with custom Class______________________________" << std::endl;
    Iterator<Math<int>, Container<Math<int>>>* it2 = cont.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        it2->Current()->print_stack();
    }
}

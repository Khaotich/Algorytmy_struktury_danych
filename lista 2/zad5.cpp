#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

template <typename T>
struct node
{
    T key;
    node* left;
    node* right;

    node(T key) : key(key), left(nullptr), right(nullptr) {}
};

template <typename T>
void insert(node<T>*& t, T x)
{
    node<T>** a = &t;
    while (*a != nullptr)
    {
        if (x < (**a).key)
            a = &(**a).left;
        else
            a = &(**a).right;
    }

    *a = new node<T>(x);
}

template <typename T>
class BSTiter
{
private:
    node<T>* current = nullptr;
    stack<node<T>*> st = stack<node<T>*>();

public:
    BSTiter(node<T>* t = nullptr, stack<node<T>*> s = stack<node<T>*>()) : current(t), st(s) {}

    BSTiter operator++()
    {
        if (current->right)
        {
            st.emplace(current);
            current = current->right;
            
            while (current->left)
            {
                st.emplace(current);
                current = current->left;
            }

            return *this;
        }

        while (!st.empty())
        {
            if (current == st.top()->left)
            {
                current = st.top();
                st.pop();
                return *this;
            }
            current = st.top();
            st.pop();
        }

        current = nullptr;
        return *this;
    }

    bool operator!=(BSTiter t)
    {
        return current != t.current;
    }

    int operator*()
    {
        return current->key;
    }
};

template <typename T>
BSTiter<T> begin(node<T>* t)
{
    while (t && t->left)
        t = t->left;

    return BSTiter<T>(t);
}

template <typename T>
BSTiter<T> end(node<T>*)
{
    return BSTiter<T>();
}

int main()
{
    node<int>* root = new node<int>(0);
    insert(root, 23);
    insert(root, 34);
    insert(root, 2);
    insert(root, 8);
    insert(root, 67);
    insert(root, 45);

    for (BSTiter<int> i = begin(root); i != end(root); ++i)
        cout << *i << endl;

    for (auto x : root)
        cout << x << endl;
}
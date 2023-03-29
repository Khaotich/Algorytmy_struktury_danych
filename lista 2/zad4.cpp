#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node *parent;

    node(int key, node *parent) : key(key), parent(parent),
                                  left(nullptr), right(nullptr) {}
};

void insert(node *&t, int x)
{
    node **a = &t;
    node *tmp = nullptr;

    while (*a != nullptr)
    {
        tmp = *a;
        if (x < (**a).key)
            a = &(**a).left;
        else
            a = &(**a).right;
    }

    *a = new node(x, tmp);
}

class BSTiter
{
private:
    node *current = nullptr;

public:
    BSTiter(node *t = nullptr) : current(t) {}

    BSTiter operator++()
    {
        if (current->right)
        {
            current = current->right;
            while (current->left)
                current = current->left;
            return *this;
        }

        while (current->parent && current == current->parent->right)
            current = current->parent;

        if (!current->parent)
        {
            current = nullptr;
            return *this;
        }

        current = current->parent;
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

BSTiter begin(node *t)
{
    while (t && t->left)
        t = t->left;

    return BSTiter(t);
}

BSTiter end(node *)
{
    return BSTiter();
}

int main()
{
    node* root = new node(0, nullptr);
    insert(root, 23);
    insert(root, 34);
    insert(root, 2);
    insert(root, 8);
    insert(root, 67);
    insert(root, 45);

    for (BSTiter i = begin(root); i != end(root); ++i)
        cout << *i << endl;

    for (auto x : root)
        cout << x << endl;
}
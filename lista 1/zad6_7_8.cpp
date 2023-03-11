#include <iostream>

using namespace std;

struct lnode
{
    int key;
    lnode* next;
    lnode(int k, lnode* n = nullptr) : key(k), next(n) {}
};

// zadanie 6.a
void wypisz(lnode* L)
{
    while (L != nullptr)
    {
        cout << L->key << " ";
        L = L->next;
    }

    cout << endl;
}

// zadanie 6.b
int suma(lnode* L)
{
    int result = 0;
    while (L != nullptr)
    {
        result += L->key;
        L = L->next;
    }

    return result;
}

// zadanie 6.c
int nty(int n, lnode* L)
{
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        if (L == nullptr)
            return 0;
        else
        {
            result = L->key;
            L = L->next;
        }
    }

    return result;
}

// zadanie 6.d
void insert(lnode*& L, int x)
{
    L = new lnode(x, L);
}

// zadanie 6.e
void insert_after_smaller(lnode*& L, int x)
{
    lnode* tmp = L;
    while (tmp != nullptr)
    {
        if (tmp->key < x) tmp->next = new lnode(x, tmp->next);
        tmp = tmp->next;
    }
}

// zadanie 6.f
void remove(lnode*& L, int x)
{
    lnode* current_L = L;
    lnode* previous_L = L;
    while (current_L != nullptr)
    {
        if (current_L->key == x)
        {
            previous_L->next = current_L->next;
            delete current_L;
            current_L = previous_L;
        }

        previous_L = current_L;
        current_L = current_L->next;
    }
}

// zadanie 6.g
void filter(lnode*& L, bool cond(int))
{
    lnode* previous_L = L;
    lnode* current_L = L;
    while (current_L != nullptr)
    {
        if (cond(current_L->key) == false)
        {
            previous_L->next = current_L->next;
            delete current_L;
            current_L = previous_L;
        }

        previous_L = current_L;
        current_L = current_L->next;
    }
}

bool function(int x)
{
    return x % 2;
}

//zadanie 6.h
void destroy(lnode*& L)
{
    while (L != nullptr)
    {
        lnode* tmp_L = L;
        L = L->next;
        delete tmp_L;
    }
}

// zadanie 7
void reverse(lnode*& L)
{
    lnode* prev_L, * next_L;
    lnode* current_L = L;
    prev_L = nullptr;
    
    while (current_L != nullptr)
    {
        next_L = current_L->next;
        current_L->next = prev_L;
        prev_L = current_L;
        current_L = next_L;
    }

    L = prev_L;
}

//zadanie 8
int tmp = 0;
lnode* merge(lnode*& L1, lnode*& L2)
{      
    if (L1 == nullptr) return L1;
    if (L2 == nullptr) return L2;

    if (L1->key > L2->key)
    {
        tmp += 1;
        L1->next = merge(L1->next, L2);
        return L1;
    }
    else
    {
        tmp += 1;
        L2->next = merge(L1, L2->next);
        return L2;
    }
}

int main()
{
    lnode* node1 = nullptr;
    insert(node1, 7);
    insert(node1, 6);
    insert(node1, 4);
    insert(node1, 3);
    insert(node1, 2);
    insert(node1, 1);

    wypisz(node1);
    cout << suma(node1);
    cout << nty(2, node1) << endl;
    cout << nty(5, node1) << endl;
    insert_after_smaller(node1, 5);
    wypisz(node1);
    remove(node1, 3);
    wypisz(node1);
    //destroy(node1);
    //wypisz(node1);

    filter(node1, &function);
    wypisz(node1);

    reverse(node1);
    wypisz(node1);

    lnode* node2 = nullptr;
    insert(node2, 1);
    insert(node2, 2);
    insert(node2, 3);
    insert(node2, 4);

    lnode* node3 = merge(node1, node2);
    wypisz(node3);
}
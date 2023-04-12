#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
    node(int key, node* n = nullptr) : value(key), next(n) {}
};

void insert(node*& L, int x)
{
    L = new node(x, L);
}

void wypisz(node* L)
{
    while (L != nullptr)
    {
        cout << L->value << " ";
        L = L->next;
    }

    cout << endl;
}

void counting_sort(node*& lista, int m) {
    int* count = new int[m](); // Inicjujemy tablicę count zerami
    node* curr = lista;

    while (curr != nullptr)
    {
        if (curr->value >= 0 && curr->value <= m)
            count[curr->value]++; // Zliczamy wystąpienia wartości spośród liczb mniejszych niż m
        curr = curr->next;
    }

    curr = lista;
    int i = 0;

    while (curr != nullptr)
    {
        while (i <= m && count[i] == 0) i++; // Szukamy pierwszej niezerowej wartości w tablicy count
        if (i <= m)
        {
            curr->value = i; // Nadpisujemy wartość węzła
            count[i]--; // Zmniejszamy licznik wystąpień wartości
        }
        curr = curr->next;
    }
}

int main()
{
    node* node1 = nullptr;
    insert(node1, 1);
    insert(node1, 3);
    insert(node1, 2);
    insert(node1, 4);
    insert(node1, 8);
    insert(node1, 6);

    cout << "Przed sortowaniem: ";
    wypisz(node1);
    counting_sort(node1, 10);
    cout << "Po sortowaniu: ";
    wypisz(node1);
}
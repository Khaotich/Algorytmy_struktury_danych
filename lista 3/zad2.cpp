#include <iostream>

using namespace std;

struct node
{
	int key;
	node* next;
	node(int k, node* n = nullptr): key(k), next(n) {}
};

void insert(int key, node*& L)
{
	L = new node(key, L);
}

void print(node* L)
{
	while (L)
	{
		cout << L->key << endl;
		L = L->next;
	}
}

void insertion_sort(node*& L)
{
    node* sorted = nullptr;

    while (L)
    {
        node* head = L;
        node** tail = &sorted;
        L = L->next;

        while (!(*tail == nullptr || head->key < (*tail)->key))
        {
            tail = &(*tail)->next;
        }

        head->next = *tail;
        *tail = head;
    }
    
    L = sorted;
}

int main()
{
	node* root = nullptr;
	insert(0, root);
	insert(1, root);
	insert(2, root);
	insert(7, root);
	insert(3, root);
	insert(5, root);
	insert(6, root);
    insertion_sort(root);

	print(root);
}
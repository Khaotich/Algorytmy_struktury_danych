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
        tmp = &(**a);
        if (x < (**a).key)  
            a = &(**a).left;
        else
            a = &(**a).right;
    }

    *a = new node(x, tmp); 
}

int H(node *t)
{
    return !t ? 0 : 1 + max(H(t->left), H(t->right));
}

void prettyLine(node *t, int &n, string c1, string c2, int level = 0)
{
    if (t)
    {
        int k = n;
        prettyLine(t->left, n, " " + c1, "-" + c1, level - 1);
        stringstream s;
        s << ' ' << t->key << ' ';
        int l = s.str().length();
        n += l;
        if (level == 0)
            cout << "" << s.str() << "";
        else if (level == -1)
        {
            for (int i = 0; i < (l) / 2; i++)
                cout << (c1[0] == ' ' ? " " : "─");

            cout << (c1[0] == ' ' ? "┌" : "┐");

            for (int i = (l) / 2 + 1; i < l; i++)
                cout << (c2[0] == ' ' ? " " : "─");
        }
        else
            for (int i = 0; i < l; i++)
                cout << (level >= 0 ? " " : c2[-level - 1] == '-' ? "─"
                                                                  : " ");
        prettyLine(t->right, n, "-" + c2, " " + c2, level - 1);
    }
}

void pretty(node *t)
{
    int h = H(t);
    char c = ' ';
    for (int i = 0; i < h; i++)
    {
        int n = 0;
        prettyLine(t, n, "", "", i);
        cout << endl;
    }
}

void increment(node *t)
{
    t->key = t->key + 1;
}

void inorder_do(node *root, void f(node *))
{
    bool leftdone = false;

    while (root)
    {
        if (!leftdone)
        {
            while (root->left)
                root = root->left;
        }

        f(root);
        leftdone = true;

        if (root->right)
        {
            leftdone = false;
            root = root->right;
        }

        else if (root->parent)
        {
            while (root->parent && root == root->parent->right)
                root = root->parent;
            if (!root->parent)
                break;
            root = root->parent;
        }
        else
            break;
    }
}

int main()
{
    node *root = new node(0, nullptr);
    insert(root, 23);
    insert(root, 34);
    insert(root, 2);
    insert(root, 8);
    insert(root, 67);
    insert(root, 45);

    pretty(root);
    inorder_do(root, increment);
    pretty(root);
}
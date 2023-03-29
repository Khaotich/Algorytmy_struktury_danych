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

void remove(node *&t, int x) 
{
    node **a = &t;        
    while (*a && (**a).key != x)     
        a = x < (**a).key ? &(**a).left : &(**a).right;

    if (*a)
    {
        if ((**a).right && (**a).left)
        {
            node **b = &(**a).right;
            while ((**b).left)
                b = &(**b).left; 
            (**a).key = (**b).key;  
            a = b; 
        }

        node *son = (**a).right ? (**a).right : (**a).left;
        son->parent = (**a).parent;
        delete *a;
        *a = son;
    }
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

int main()
{
    node *root = new node(0, nullptr);
    insert(root, 23);
    insert(root, 34);

    pretty(root);
    node *tmp = root;
    cout << "Adres glowy: " << tmp << endl;
    cout << "Adres prawego dziecka: " << tmp->right << endl;
    tmp = tmp->right; // przechodzimy na prawe dziecko
    cout << "Adres rodzica: " << tmp->parent << endl;

    node *tmp2 = root;
    insert(tmp2, 12);
    insert(tmp2, 45);
    pretty(tmp2);
    remove(tmp2, 23);
    pretty(tmp2);
    cout << "Adres głowy: " << tmp2 << endl;
    cout << "Adres prawego dziecka: " << tmp->right << endl;
    tmp2 = tmp2->right; // przechodzimy na prawe dziecko
    cout << "Adres rodzica: " << tmp->parent << endl;
}
#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>

using namespace std;

struct BSTnode
{
	int key;
	int nL;
	BSTnode* left;
	BSTnode* right;
	BSTnode* parent;
	BSTnode(int k, BSTnode* p = nullptr): key(k), nL(0), parent(p), left(nullptr), right(nullptr) {}
};

void insert(BSTnode*& t, int x)
{
	BSTnode** t1 = &t;
	BSTnode* prev = nullptr;

	while (*t1)
	{
		prev = *t1;
		if (x < (*t1)->key)
		{
			(*t1)->nL++;
			t1 = &(*t1)->left;
		}
		else
			t1 = &(*t1)->right;
	}

	*t1 = new BSTnode(x, prev);
}

int n(BSTnode* t)   // ilość kluczy w drzewie
{
	return  t ?  // jeśli drzewo nie jest puste
		1 + n(t->left) + n(t->right) : // korzeń + lewe + prawe
		0;  // puste drzewo ma 0 kluczy
}

BSTnode* ity(BSTnode* t, int i)
{
	if (i >= n(t) || i < 0)
		return nullptr;

	while (true)
	{
		if (i == t->nL)
			return t;
		else if (i < t->nL)
			t = t->left;
		else
		{
			i -= (t->nL + 1);
			t = t->right;
		}
	}
}

int H(BSTnode* t)
{
	return !t ? 0 : 1 + max(H(t->left), H(t->right));
}

void prettyLine(BSTnode* t, int& n, string c1, string c2, int level = 0)
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

void pretty(BSTnode* t)
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
	BSTnode* root = new BSTnode(0);
	insert(root, 1);
	insert(root, 3);
	insert(root, -1);
	insert(root, -2);
	insert(root, 4);
	insert(root, 2);

	pretty(root);

	BSTnode* root2 = ity(root, 2);
	cout << root2->nL;
}
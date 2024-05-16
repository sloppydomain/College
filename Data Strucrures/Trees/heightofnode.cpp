#include <iostream>
using namespace std;
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};
Node *newnode(int x)
{
    Node *t = new Node;
    t->val = x;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}
int height(Node *p, int x, int &h)
{
    if (p == nullptr)
        return 0;
    int lheight = height(p->left, x, h);
    int rheight = height(p->right, x, h);
    int ans = max(lheight, rheight) + 1;
    if (p->val == x)
        h = ans;
    return ans;
}

int main()
{
    Node *t = newnode(9);
    t->left = newnode(8);
    t->right = newnode(3);
    t->left->right = newnode(7);
    t->left->left = newnode(6);
    int x;
    int h = 0;
    cout << "Enter the node : ";
    cin >> x;
    height(t, x, h);
    cout << "Height of " << x << " is : " << h;
    return 0;
}
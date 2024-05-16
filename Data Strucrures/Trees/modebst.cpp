#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
TreeNode *newnode(int x)
{
    TreeNode *t = new TreeNode;
    t->val = x;
    t->left = nullptr;
    t->right = nullptr;
    return t;
}
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
int mx = -1;
vector<int> findMode(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    unordered_map<int, int> mp;
    for (int i = 0; i < ans.size(); i++)
    {
        mp[ans[i]]++;
        mx = max(mx, mp[ans[i]]);
    }
    vector<int> v;
    unordered_map<int, int>::iterator i;
    for (i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second == mx)
            v.push_back(i->first);
    }
    return v;
}
int main()
{
    TreeNode *t = newnode(9);
    t->left = newnode(8);
    t->right = newnode(8);
    t->left->right = newnode(6);
    t->left->left = newnode(6);
    vector<int> ans;
    ans = findMode(t);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 1e9 + 7
#define mxn 1e18
class Solution
{
    vector<int> ans;

public:
    void max_e(TreeNode *root, int d)
    {
        if (root == nullptr)
            return;
        if (d == ans.size())
            ans.push_back(root->val);
        else
            ans[d] = max(ans[d], root->val);
        max_e(root->left, d + 1);
        max_e(root->right, d + 1);
    }
    vector<int> largestValues(TreeNode *root)
    {
        max_e(root, 0);
        return ans;
    }
};
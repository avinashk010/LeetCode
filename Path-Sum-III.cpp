1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
10 * right(right) {}
11 * };
12 */
13class Solution {
14public:
15    long long ans = 0;
16    void f2(TreeNode* root, int target,long long sum){
17        if(!root) return;
18
19        if((long long)root->val + sum == target) ans++;
20        f2(root->left,target, sum+root->val);
21        f2(root->right,target, sum+root->val);
22    }
23
24    void liveSum(TreeNode* root, int target) {
25        if (!root)
26            return;
27
28        liveSum(root->left, target);
29        liveSum(root->right, target);
30
31        f2(root, target,0LL);
32
33        return;
34    }
35    int pathSum(TreeNode* root, int targetSum) {
36        liveSum(root, targetSum);
37        return ans;
38    }
39};
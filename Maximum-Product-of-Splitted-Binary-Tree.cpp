1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    long long sum = 0;
15    void h(TreeNode* root){
16        if(!root ) return;
17
18        sum+= root->val;
19        h(root->left);
20        h(root->right);
21    }
22    long long ans = 0;
23    long long h2(TreeNode* root){
24        if(!root) return 0;
25
26
27        int left = h2(root->left);
28        int right = h2(root->right);
29
30        int now = root->val + left + right;
31        ans = max(ans, (sum-now) * now);
32        return now;
33    }
34    int maxProduct(TreeNode* root) {
35        h(root);
36        h2(root);
37        const int mod = 1e9+7;
38        return ans%mod;
39    }
40};
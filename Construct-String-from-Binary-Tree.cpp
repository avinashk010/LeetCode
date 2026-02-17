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
14    string ans;
15    void h(TreeNode* root){
16        if(!root) return;
17
18        ans += to_string(root->val);
19        if(root->left || root->right){
20            ans += '(';
21            h(root->left);
22            ans += ')';
23        }
24        if(root->right){
25            ans += '(';
26            h(root->right);
27            ans += ')';
28        }
29
30    }
31    string tree2str(TreeNode* root) {
32        ans = "";
33        h(root);
34        return ans;
35    }
36};
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* ans = NULL;
13    bool h(TreeNode* root, TreeNode* p, TreeNode* q){
14        if(!root) return false;
15
16
17        bool left = h(root->left, p, q);
18        bool right = h(root->right, p, q);
19
20
21        if(left && right){
22            if(!ans) ans = root;
23            return true;
24        }
25
26
27        if(left || right){
28            if(root == p || root == q){
29                if(!ans) ans = root;
30            }
31            return true;
32        }
33
34        
35        
36        if(root == p || root == q){
37            return true;
38        }
39
40        return false;
41
42    }
43    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
44        h(root,p,q);
45        return ans;
46    }
47};
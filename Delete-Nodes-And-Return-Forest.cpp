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
14    vector<TreeNode*>ans;
15    TreeNode* h(TreeNode* root,set<int>&st){
16        if(!root) return NULL;
17
18        root->left = h(root->left,st);
19        root->right = h(root->right,st);
20
21        //at this point, niche sb saaf 
22        if(st.find(root->val) != st.end()){
23            if(root->left){
24                ans.push_back(root->left);
25            }
26            if(root->right){
27                ans.push_back(root->right);
28            }
29            return NULL;
30        }
31
32        return root;
33
34    }
35    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
36        set<int>st(to_delete.begin(),to_delete.end());
37        TreeNode* base = h(root,st);
38        
39        if(base){
40            ans.push_back(base);
41        }
42        
43        return ans; 
44    }
45};
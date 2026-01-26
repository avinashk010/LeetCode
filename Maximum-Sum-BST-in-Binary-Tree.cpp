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
14    long long ans=0;
15    
16    pair<long long,pair<long long,long long>> h(TreeNode* root){ //sum, min, max
17        if(!root) return {0,{INT_MAX, INT_MIN}};
18
19
20        auto l = h(root->left);
21        auto r = h(root->right);
22
23        long long val = root->val;
24        long long sum = l.first+r.first;
25
26        long long mini = min({val, l.second.first, r.second.first});
27        int maxi = max({val, l.second.second, r.second.second});
28
29        if(mini == INT_MIN || maxi == INT_MAX){
30            return {INT_MIN,{INT_MIN, INT_MAX}};
31        }
32
33        if(val > l.second.second && val < r.second.first){ //bst
34            sum += val;
35            ans = max(ans, sum);
36        }else{
37            return {INT_MIN,{INT_MIN, INT_MAX}};
38        }
39        return {sum,{mini, maxi}};
40    }
41
42    int maxSumBST(TreeNode* root) {
43        h(root);
44        return ans;
45    }
46};
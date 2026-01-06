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
14    int maxLevelSum(TreeNode* root) {
15        int ans = -1;
16        int maxi = INT_MIN;
17
18        queue<TreeNode*>q;
19        q.push(root);
20        int l =1;
21        long long sum=0;
22        while(!q.empty()){
23            int size = q.size();
24
25            for(int i=0; i<size; i++){
26                TreeNode* tp = q.front();
27                q.pop();
28                sum+= tp->val;
29                if(tp->left){
30                    q.push(tp->left);
31                }
32                if(tp->right){
33                    q.push(tp->right);
34                }
35
36            }
37            if(sum > maxi){
38                maxi = sum;
39                ans = l;
40            }
41            sum = 0;
42            l++;
43        }
44        return ans;
45    }
46};
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
14    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
15        if (!root) return nullptr;
16
17        unordered_map<TreeNode*, TreeNode*> parent;
18        queue<TreeNode*> q;
19        q.push(root);
20        parent[root] = nullptr;
21
22        vector<TreeNode*> lastLevel;
23
24        // BFS traversal
25        while (!q.empty()) {
26            int size = q.size();
27            lastLevel.clear();
28
29            for (int i = 0; i < size; i++) {
30                TreeNode* node = q.front();
31                q.pop();
32                lastLevel.push_back(node);
33
34                if (node->left) {
35                    parent[node->left] = node;
36                    q.push(node->left);
37                }
38                if (node->right) {
39                    parent[node->right] = node;
40                    q.push(node->right);
41                }
42            }
43        }
44
45        unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());
46
47        // Move upward until one node remains
48        while (deepest.size() > 1) {
49            unordered_set<TreeNode*> next;
50            for (auto node : deepest) {
51                next.insert(parent[node]);
52            }
53            deepest = next;
54        }
55
56        return *deepest.begin();
57    }
58};
1class Solution {
2public:
3    bool dfs(int n, unordered_map<int, list<int>>& adj, vector<int>& ans,
4             vector<int>& vis) {
5        vis[n] = 1;
6        for (auto& it : adj[n]) {
7            if (vis[it] == 0) {
8                if (!dfs(it, adj, ans, vis))
9                    return false;
10            } else if (vis[it] == 1) {
11                return false;
12            }
13        }
14        vis[n] = 2;
15        ans.push_back(n);
16        return true;
17    }
18    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
19        vector<int> ans;
20        unordered_map<int, list<int>> adjlist;
21        vector<int> vis(numCourses,
22                        0); // 0=not visited, 1=visited, 2= full processed
23        for (int i = 0; i < prerequisites.size(); i++) {
24            int todo = prerequisites[i][0];
25            int dothis = prerequisites[i][1];
26            adjlist[dothis].push_back(todo);
27        }
28        for (int i = 0; i < numCourses; i++) {
29            if (vis[i] == 0)
30                if (!dfs(i, adjlist, ans, vis))
31                    return {};
32        }
33        reverse(ans.begin(), ans.end());
34        return ans;
35    }
36};
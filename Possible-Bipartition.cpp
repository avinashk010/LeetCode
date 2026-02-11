1class Solution {
2public:
3    class DSU {
4    public:
5        vector<int> p;
6        vector<int> rank;
7        DSU(int n) {
8            p.resize(n);
9            rank.resize(n, 0);
10            for (int i = 0; i < n; i++) {
11                p[i] = i;
12            }
13        }
14        int fp(int u) {
15            if (p[u] == u)
16                return u;
17            return p[u] = fp(p[u]);
18        }
19        int unite(int a, int b) {
20            a = fp(a);
21            b = fp(b);
22            if (a == b) {
23                return 0;
24            }
25            if (rank[a] == rank[b]) {
26                p[b] = a;
27                rank[a]++;
28            } else if (rank[a] > rank[b]) {
29                p[b] = a;
30            } else {
31                p[a] = b;
32            }
33            return 1;
34        }
35    };
36    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
37        vector<vector<int>> adj(n + 1);
38
39        for (auto& d : dislikes) {
40            adj[d[0]].push_back(d[1]);
41            adj[d[1]].push_back(d[0]);
42        }
43
44        DSU dsu(n + 1);
45
46        for (int i = 1; i <= n; i++) {
47            for (int j = 0; j < adj[i].size(); j++) {
48
49                if (dsu.fp(i) == dsu.fp(adj[i][j]))
50                    return false;
51
52                if (j > 0) {
53                    dsu.unite(adj[i][0], adj[i][j]);
54                }
55            }
56        }
57        return true;
58    }
59};
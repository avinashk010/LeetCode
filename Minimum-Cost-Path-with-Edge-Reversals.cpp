1class Solution {
2public:
3
4
5
6    vector<int> dijkstra(int n, int src, vector<vector<pair<int, int>>>& adj) {
7        vector<int> dist(n, INT_MAX);
8        dist[src] = 0;
9
10        priority_queue<pair<int, int>, vector<pair<int, int>>,
11                       greater<pair<int, int>>>
12            pq;
13        pq.push({0, src}); 
14
15        while (!pq.empty()) {
16            auto [d, u] = pq.top();
17            pq.pop();
18
19            if (d > dist[u])
20                continue; 
21
22            for (auto [v, w] : adj[u]) {
23                if (dist[u] + w < dist[v]) {
24                    dist[v] = dist[u] + w;
25                    pq.push({dist[v], v});
26                }
27            }
28        }
29        return dist;
30    }
31
32    int minCost(int n, vector<vector<int>>& edges) {
33        vector<vector<pair<int, int>>> adj(n);
34        for (int i = 0; i < edges.size(); i++) {
35            int x = edges[i][0];
36            int y = edges[i][1];
37            int w = edges[i][2];
38
39            adj[x].push_back({y, w});
40            adj[y].push_back({x, 2 * w});
41        }
42
43        vector<int>dis = dijkstra(n,0,adj);
44    
45        return dis[n-1] == INT_MAX? -1: dis[n-1];
46
47    }
48};
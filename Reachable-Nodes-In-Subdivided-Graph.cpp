1class Solution {
2public:
3
4    // map<pair<int,int>,int>mp;
5    vector<vector<pair<int,int>>>adj;
6    // vector<bool>vis;
7    
8    // void dfs(int n, int p,int left){
9    //     if(vis[n]) return;
10
11    //     vis[n] = true;
12
13    //     for(auto e : adj[n]){
14            
15    //         int nbr = e.first;
16    //         if(nbr == p) continue;
17    //         int cost = e.second;
18    //         cost++;
19
20    //         // int mini = min(n,nbr);
21    //         // int maxi = max(n,nbr);
22    //         if(left >= cost){
23    //             mp[{n, nbr}] = cost;
24    //             dfs(nbr,n,left-cost);
25    //         }else{
26    //             int val = mp[{n,nbr}];
27    //             mp[{n, nbr}] = max(val, left);
28    //         }
29    //     }
30
31    //     vis[n] = false;
32    //     return;
33    // }
34
35    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
36        adj.assign(n,vector<pair<int,int>>());
37        // vis.assign(n,false);
38        // map<pair<int,int>,int>costs;
39        for(int i=0; i<edges.size(); i++){
40            int u = edges[i][0];
41            int v = edges[i][1];
42            int c = edges[i][2];
43
44            adj[v].push_back({u,c});
45            adj[u].push_back({v,c});
46            // costs[{u,v}] = c+1;
47            // costs[{v,u}] = c+1;
48        }
49
50        // dfs(0,-1,maxMoves);
51
52        
53
54
55
56        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
57
58        vector<int>dis(n,INT_MAX);
59        dis[0] = 0;
60
61        pq.push({0,0});
62        while(!pq.empty()){
63            int tp = pq.top().second;
64            int cost = pq.top().first;
65            pq.pop();
66
67            if(cost > dis[tp]) continue;
68
69            for(auto& e : adj[tp]){
70                if(e.second + cost + 1 < dis[e.first]){
71                    // if(e.second + cost + 1 > maxMoves){
72                    //     int left = maxMoves - cost;
73                    //     mp[{tp, e.first}] = left;
74                    //     continue;
75                    // }
76                    dis[e.first] = e.second + cost + 1; 
77                    pq.push({e.second+cost+1, e.first});
78                    // mp[{tp,e.second}] = e.second+1;
79
80                }
81            }
82        }
83
84        int ans = 0;
85
86
87        for(int i = 0; i < n; i++){
88            if(dis[i] <= maxMoves) ans++;
89        }
90
91
92        for(auto &e : edges){
93            int u = e[0];
94            int v = e[1];
95            int c = e[2];
96
97            int fromU = max(0, maxMoves - dis[u]);
98            int fromV = max(0, maxMoves - dis[v]);
99
100            ans += min(c, fromU + fromV);
101        }
102
103
104        return ans; 
105    }
106};
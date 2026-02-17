1class Solution {
2public:
3    int count = 0;
4    void dfs(int i,int p,int w, vector<vector<pair<int,int>>>&adj, int ss){
5        
6        if(w % ss == 0) count++;
7        
8        for(auto &nbr : adj[i]){
9            if(nbr.first == p) continue;
10
11
12
13            dfs(nbr.first, i, nbr.second+w, adj,ss);
14            
15        }
16
17    }
18    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
19        int n = edges.size()+1;
20        vector<vector<pair<int,int>>>adj(n);
21
22        for(int i=0; i<edges.size(); i++){
23            int u = edges[i][0]; 
24            int v = edges[i][1]; 
25            int c = edges[i][2]; 
26
27            adj[u].push_back({v,c});
28            adj[v].push_back({u,c});
29        }
30        
31        vector<int>ans(n,0);
32
33    
34        
35        for(int i=0; i<n; i++){
36            
37            int res = 0;
38            int now_tot = 0;
39            for(int x = 0; x<adj[i].size(); x++){
40                count = 0;
41                dfs(adj[i][x].first,i,adj[i][x].second,adj,signalSpeed);
42                res += now_tot* count;
43                now_tot += count;
44            }
45            
46            ans[i] = res;
47        }
48
49        return ans;
50
51    }
52};
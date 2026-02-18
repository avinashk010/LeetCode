1class Solution {
2public:
3
4    vector<string>ans;
5    int size;
6   void dfs(string u,
7         unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj,
8         vector<string>& path) {
9
10    auto& pq = adj[u];
11    while (!pq.empty()) {
12        string v = pq.top();
13        pq.pop();
14        dfs(v, adj, path);
15    }
16    path.push_back(u);
17}
18
19    vector<string> findItinerary(vector<vector<string>>& tickets) {
20        size = tickets.size();
21        
22        unordered_map<string,priority_queue<string, vector<string>, greater<string>>>adj;
23
24        for(int i=0; i<tickets.size(); i++){
25            adj[tickets[i][0]].push(tickets[i][1]);
26        }
27       
28
29        vector<string>temp;
30        dfs("JFK", adj, temp);
31
32        reverse(temp.begin(),temp.end());
33      
34        return temp;
35
36    }
37};
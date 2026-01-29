1class Solution {
2public:
3
4    vector<long long> d(long long s, vector<vector<pair<long long,long long>>>&adj){
5        vector<long long>dis(26,LLONG_MAX);
6        dis[s] = 0;
7        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
8        pq.push({0,s});
9        while(!pq.empty()){
10            auto t = pq.top();
11            pq.pop();
12            if(t.first > dis[t.second]) continue;
13
14            for(auto &nbr : adj[t.second]){
15                if(dis[nbr.first] > t.first + nbr.second){
16                    dis[nbr.first] = t.first + nbr.second;
17                    pq.push({dis[nbr.first], nbr.first});
18                }
19            }
20        }
21
22        return dis;
23
24    }
25
26    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
27        
28        vector<vector<pair<long long,long long>>>adj(26);
29        for(long long i=0; i<original.size(); i++){
30            long long u = original[i]-'a';
31            long long v = changed[i]-'a';
32            long long c = cost[i];
33
34            adj[u].push_back({v,c});
35        }
36
37        vector<vector<long long>>val(27,vector<long long>(27,0));
38        for(long long i=0; i<26; i++){
39            val[i] = d(i,adj);
40        }
41
42
43        long long ans =0;
44        for(long long i=0; i<source.length(); i++){
45            long long now = val[source[i]-'a'][target[i]-'a'];
46            if(now == LLONG_MAX){
47                return -1;
48            }
49            ans += now;
50        }
51        // if(ans >= LLONG_MAX) return -1;
52        return ans;
53    }
54};
1class Solution {
2public:
3    map<string, int> d(string& s, map<string, vector<pair<string, int>>>& adj) {
4        map<string, int> dis;
5        dis[s] = 0;
6        priority_queue<pair<int, string>, vector<pair<int, string>>,
7                       greater<pair<int, string>>>
8            pq;
9        pq.push({0, s});
10
11        while (!pq.empty()) {
12            auto t = pq.top();
13            pq.pop();
14            string now = t.second;
15            int nowCost = t.first;
16
17            if (dis[now] < nowCost)
18                continue;
19
20            for (auto& e : adj[now]) {
21                if (dis.find(e.first) != dis.end()) {
22                    if (dis[e.first] > nowCost + e.second) {
23                        dis[e.first] = nowCost + e.second;
24                        pq.push({dis[e.first], e.first});
25                    }
26                } else {
27                    dis[e.first] = nowCost + e.second;
28                    pq.push({dis[e.first], e.first});
29                }
30            }
31        }
32
33        return dis;
34    }
35    vector<int> lens;
36    vector<long long> dp;
37    int max_len = 0;
38    long long INF = LLONG_MAX;
39
40    long long h(int x, string& from, string& to,
41                unordered_map<string, map<string, int>>& vals) {
42
43        if (x >= from.size())
44            return 0;
45        if (dp[x] != -1)
46            return dp[x];
47
48        long long one = INF;
49
50        if (from[x] == to[x]) {
51            one = min(one, h(x + 1, from, to, vals));
52        }
53
54        for (int len : lens) {
55            if (x + len > from.size())
56                continue;
57
58            string a = from.substr(x, len);
59            auto it = vals.find(a);
60            if (it == vals.end())
61                continue;
62
63            string b = to.substr(x, len);
64            if (it->second.count(b)) {
65                long long sub = h(x + len, from, to, vals);
66                if (sub < INF)
67                    one = min(one, sub + it->second[b]);
68            }
69        }
70
71        return dp[x] = one;
72    }
73
74    long long minimumCost(string& source, string& target,
75                          vector<string>& original, vector<string>& changed,
76                          vector<int>& cost) {
77        dp.assign(source.length(), -1);
78        map<string, vector<pair<string, int>>> adj;
79        for (int i = 0; i < original.size(); i++) {
80            adj[original[i]].push_back({changed[i], cost[i]});
81        }
82
83        unordered_set<int> seen;
84        for (auto& s : original) {
85            if (seen.insert(s.size()).second)
86                lens.push_back(s.size());
87        }
88
89        for (auto& s : original)
90            max_len = max(max_len, (int)s.size());
91
92        unordered_map<string, map<string, int>> vals;
93
94        for (int i = 0; i < original.size(); i++) {
95            vals[original[i]] = d(original[i], adj);
96        }
97
98        // cout<<vals["d"]["e"];
99
100        long long ans = h(0, source, target, vals);
101        if (ans >= INF)
102            return -1;
103        return ans;
104    }
105};
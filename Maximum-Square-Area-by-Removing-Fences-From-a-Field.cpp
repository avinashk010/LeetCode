1class Solution {
2public:
3    const int MOD = 1e9+7;
4    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
5        long long ans = -1;
6       set<long long>mp;
7        hFences.push_back(1);
8        hFences.push_back(m);
9        for(long long i =0; i<hFences.size(); i++){
10            for(long long j = i+1; j<hFences.size(); j++){
11                long long val = abs(hFences[j] - hFences[i]);
12                // val = val%MOD;
13                mp.insert(val);
14            }
15        }
16
17        vFences.push_back(1);
18        vFences.push_back(n);
19        for(long long i =0; i<vFences.size(); i++){
20            for(long long j = i+1; j<vFences.size(); j++){
21                long long val = abs(vFences[i] - vFences[j]);
22                // val = val%MOD;
23                if(mp.find(val) != mp.end()){
24                    ans = max(ans, (val*val));
25                    // ans = (ans+MOD)%MOD;
26                }
27            }
28        }
29        return ans%MOD;
30
31        
32    }
33};
1class Solution {
2public:
3    long long minCost(string s, vector<int>& cost) {
4        vector<long long>c(26,0);
5        for(int i =0; i<s.length(); i++){
6            c[s[i]-'a'] += cost[i];
7        }
8        long long total = accumulate(c.begin(),c.end(),0LL);
9        long long maxi = *max_element(c.begin(),c.end());
10        return total - maxi;
11        
12    }
13};
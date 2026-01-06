1class Solution {
2public:
3    const int mod = 1e9+7;
4    int rangeSum(vector<int>& nums, int n, int left, int right) {
5        vector<long long>v;
6        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
7        for(long long i =0; i<n; i++){
8            pq.push({nums[i], i});
9        }
10        while(!pq.empty()){
11            auto top = pq.top();
12            pq.pop();
13            v.push_back(top.first);
14            long long n_i = top.second +1;
15            if(n_i < n){
16                pq.push({top.first+nums[n_i], n_i});
17            }
18        }
19        long long ans =0;
20        for(long long i =left-1; i<right; i++){
21            ans += v[i];
22            ans = ans%mod;
23        }
24        return ans;
25    }
26};
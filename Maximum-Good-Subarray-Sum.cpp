1class Solution {
2public:
3    long long sum(int i1, int i2, vector<long long>&pre){
4        if(i1 == 0){
5            return pre[i2];
6        }
7        return pre[i2] - pre[i1-1];
8    }
9
10    long long maximumSubarraySum(vector<int>& nums, int k) {
11
12        vector<long long>presum(nums.size(), 0);
13        presum[0] = nums[0];
14
15        for(int i=1; i<nums.size(); i++){
16            presum[i] = presum[i-1] + nums[i];
17        }
18
19        unordered_map<int,int>mp;
20
21        long long ans = LONG_MIN; 
22        for(int i=0; i<nums.size(); i++){
23            int need1 = -k + nums[i];
24            int need2 = k + nums[i];
25
26            long long sum1 = LLONG_MIN;
27            if(mp.find(need1) != mp.end()){
28                sum1 = sum(mp[need1], i, presum);
29            }
30            long long sum2 = LLONG_MIN;
31            if(mp.find(need2) != mp.end()){
32                sum2 = sum(mp[need2], i, presum);
33            }
34
35            // cout<<i<<" "<<sum1<<" "<<sum2<<endl;
36            ans = max({ans,sum1, sum2});
37
38
39            if(mp.find(nums[i]) != mp.end()){
40                int i1 = mp[nums[i]];
41                int i2 = i;
42                // long long store = sum(i1, i2, presum);
43                if (presum[i] < presum[mp[nums[i]]]) {
44                    mp[nums[i]] = i;
45                }
46            }else{
47                mp[nums[i]] = i;
48            }
49        }
50
51        if(ans == LLONG_MIN) return 0;
52
53        return ans;
54    }
55};
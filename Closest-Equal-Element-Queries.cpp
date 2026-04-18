1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4        unordered_map<int, vector<int>> mp;
5
6        int n = nums.size();
7
8        auto dist = [&](int a, int b) {
9            return min(abs(a - b), n - abs(a - b));
10        };
11
12        for (int i = 0; i < nums.size(); i++) {
13            mp[nums[i]].push_back(i);
14        }
15
16        vector<int> ans(queries.size(), -1);
17
18        for (int i = 0; i < queries.size(); i++) {
19            auto lb = lower_bound(mp[nums[queries[i]]].begin(),
20                                  mp[nums[queries[i]]].end(), queries[i]);
21            auto ub = upper_bound(mp[nums[queries[i]]].begin(),
22                                  mp[nums[queries[i]]].end(), queries[i]);
23
24            int tp = INT_MAX;
25
26            if (mp[nums[queries[i]]].size() == 1)
27                continue;
28
29            if (lb != mp[nums[queries[i]]].begin()) {
30                lb--;
31                tp = min(tp, dist(*lb, queries[i]));
32            } else {
33                tp = min(tp, dist(queries[i], mp[nums[queries[i]]].back()));
34            }
35
36            if (ub != mp[nums[queries[i]]].end()) {
37                tp = min(tp, dist(*ub, queries[i]));
38            } else {
39                tp = min(tp, dist(queries[i], mp[nums[queries[i]]][0]));
40            }
41
42            if (tp != INT_MAX && tp != 0) {
43                ans[i] = tp;
44            }
45        }
46
47        return ans;
48    }
49};
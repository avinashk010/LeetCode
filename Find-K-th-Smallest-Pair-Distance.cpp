1class Solution {
2public:
3    bool posi(int m, vector<int>& nums, int k) {
4        int count = 0;
5        int n = nums.size();
6
7        for (int i = 0; i < n; i++) {
8            int tf = nums[i] + m;
9
10            auto ub = upper_bound(nums.begin(), nums.end(), tf);
11            int ind = ub - nums.begin();
12            count += ind - i - 1;
13
14            if (count >= k)
15                return true;
16        }
17        return false;
18    }
19
20    int smallestDistancePair(vector<int>& nums, int k) {
21        int l = 0;
22        sort(nums.begin(), nums.end());
23        int h = nums.back();
24
25        int ans = -1;
26
27        while (l <= h) {
28            int m = l + (h - l) / 2;
29            if (posi(m, nums, k)) {
30                ans = m;
31                h = m - 1;
32            } else {
33                l = m + 1;
34            }
35        }
36
37        return ans;
38    }
39};
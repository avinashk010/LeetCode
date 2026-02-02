1class Solution {
2public:
3    long long minimumCost(vector<int>& nums, int k, int dist) {
4        long long ans = LLONG_MAX;
5        long long n = nums.size();
6        long long j = n - 1;
7        long long i = j - dist;
8        multiset<long long> small;
9        multiset<long long> big;
10        vector<long long> val;
11        for (long long x = i; x < j; x++) {
12            val.push_back(nums[x]);
13        }
14        long long now = 0;
15        sort(val.begin(), val.end());
16        for (long long x = 0; x < val.size(); x++) {
17            if (x < k - 2) {
18                small.insert(val[x]);
19                now += val[x];
20            } else {
21                big.insert(val[x]);
22            }
23        }
24
25        bool last = false;
26
27        while (j - i + 1 >= k - 1) {
28            now += nums[j];
29
30            ans = min(ans, nums[0] + now);
31
32            now -= nums[j];
33
34            i--;
35            if (i == 0) {
36                last = true;
37                i = 1;
38            }
39            j--;
40
41            if (!small.empty() && nums[j] <= *prev(small.end())) {
42                auto it = small.find(nums[j]);
43                if (it != small.end()) {
44                    now -= nums[j];
45                    small.erase(it);
46                } else {
47                    big.erase(big.find(nums[j]));
48                }
49            } else {
50                big.erase(big.find(nums[j]));
51            }
52
53            if (!last) {
54                if (!small.empty() && nums[i] < *prev(small.end())) {
55                    small.insert(nums[i]);
56                    now += nums[i];
57
58                    auto it = prev(small.end());
59                    big.insert(*it);
60                    now -= *it;
61                    small.erase(it);
62                } else {
63                    big.insert(nums[i]);
64                }
65            }
66
67            while (small.size() < k - 2 && big.size() != 0) {
68                small.insert(*big.begin());
69                now += *big.begin();
70                big.erase(big.begin());
71            }
72        }
73
74        return ans;
75    }
76};
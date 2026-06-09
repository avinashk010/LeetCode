1class Solution {
2public:
3    vector<vector<int>> dp;
4
5    int h(int i, int now, vector<int>& vec) {
6        if (i == vec.size())
7            return now;
8
9        if (dp[i][now] != -1)
10            return dp[i][now];
11
12        int take = now;
13        if (vec[i] > now)
14            take = h(i + 1, now + vec[i], vec);
15
16        int skip = h(i + 1, now, vec);
17
18        return dp[i][now] = max(take, skip);
19    }
20
21    int maxTotalReward(vector<int>& vec) {
22        sort(vec.begin(), vec.end());
23
24        dp.assign(vec.size() + 1, vector<int>(4001, -1));
25
26        return h(0, 0, vec);
27    }
28};
1class Solution {
2public:
3    int n, m;
4    vector<vector<vector<long long>>> dp;
5    vector<pair<int,pair<int,int>>> pq;
6    vector<vector<long long>> best; // best[k][idx]
7
8    long long h(int i, int j, int k, vector<vector<int>>& g) {
9        if (i >= n || j >= m) return LLONG_MAX / 4;
10        if (i == n-1 && j == m-1) return 0;
11
12        long long &res = dp[i][j][k];
13        if (res != -1) return res;
14
15        long long one = LLONG_MAX / 4, two = LLONG_MAX / 4;
16
17        if (i + 1 < n)
18            one = g[i+1][j] + h(i+1, j, k, g);
19
20        if (j + 1 < m)
21            two = g[i][j+1] + h(i, j+1, k, g);
22
23        long long three = LLONG_MAX / 4;
24        if (k > 0) {
25            int val = g[i][j];
26            int idx = upper_bound(
27                pq.begin(), pq.end(),
28                make_pair(val, make_pair(INT_MAX, INT_MAX))
29            ) - pq.begin() - 1;
30
31            if (idx >= 0)
32                three = best[k-1][idx];
33        }
34
35        return res = min({one, two, three});
36    }
37
38    int minCost(vector<vector<int>>& grid, int k) {
39        n = grid.size();
40        m = grid[0].size();
41
42        dp.assign(n, vector<vector<long long>>(m, vector<long long>(k+1, -1)));
43
44        for (int i = 0; i < n; i++)
45            for (int j = 0; j < m; j++)
46                pq.push_back({grid[i][j], {i, j}});
47
48        sort(pq.begin(), pq.end());
49
50        best.assign(k, vector<long long>(pq.size(), LLONG_MAX / 4));
51
52        for (int kk = 0; kk < k; kk++) {
53            for (int x = 0; x < pq.size(); x++) {
54                auto [i, j] = pq[x].second;
55                long long cur = h(i, j, kk, grid);
56                best[kk][x] = (x == 0 ? cur : min(best[kk][x-1], cur));
57            }
58        }
59
60        return h(0, 0, k, grid);
61    }
62};
63
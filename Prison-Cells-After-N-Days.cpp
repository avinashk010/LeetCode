1class Solution {
2public:
3    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
4        vector<int> ans(65, 0);
5        unordered_map<int,int> val;
6
7        int till = min(65, n);
8
9        int zero_day = 0;
10        for (int i = 0; i < 8; i++) {
11            if (cells[i]) {
12                zero_day += (1 << i);
13            }
14        }
15
16        // val.insert(zero_day);
17        val[zero_day] = 0;
18        int cycle_start = 0;
19
20        ans[0] = zero_day;
21
22        int upton = 65;
23
24        for (int i = 1; i <= till; i++) {
25            vector<int> newv(8, 0);
26            for (int x = 1; x <= 6; x++) {
27                if (cells[x + 1] == cells[x - 1]) {
28                    newv[x] = 1;
29                }
30            }
31            cells = newv;
32            int now_day = 0;
33            for (int xx = 0; xx <= 7; xx++) {
34                if (cells[xx]) {
35                    now_day += (1 << xx);
36                }
37            }
38            if (val.find(now_day) == val.end()) {
39                ans[i] = now_day;
40                val[now_day] = i;
41            } else {
42                cycle_start = val[now_day];
43                upton = i;
44                break;
45            }
46        }
47        vector<int> finalans(8, 0);
48
49        int cycle_len = upton - cycle_start;
50        int pos = cycle_start + (n - cycle_start) % cycle_len;
51
52        int ansval = ans[pos];
53
54        for (int i = 0; i < 8; i++) {
55            if (ansval & (1 << i)) {
56                finalans[i] = 1;
57            }
58        }
59
60        return finalans;
61    }
62};
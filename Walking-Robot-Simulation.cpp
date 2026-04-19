1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4        unordered_map<int, set<int>> xob;
5        unordered_map<int, set<int>> yob;
6
7        for (int i = 0; i < obstacles.size(); i++) {
8            int x = obstacles[i][0];
9            int y = obstacles[i][1];
10
11            xob[x].insert(y);
12            yob[y].insert(x);
13        }
14
15        int nowx = 0;
16        int nowy = 0;
17
18        int d = 0;
19
20        int ans = 0;
21
22        for (int i = 0; i < commands.size(); i++) {
23            int c = commands[i];
24            if (c < 0) {
25                if (c == -1) { // right
26                    d++;
27                    if (d == 4) {
28                        d = 0;
29                    }
30                } else {
31                    d--;
32                    if (d == -1) {
33                        d = 3;
34                    }
35                }
36            } else {
37                if (d == 0) {
38                    auto it = xob[nowx].upper_bound(nowy);
39                    if (it == xob[nowx].end()) {
40                        nowy += c;
41                    } else {
42                        int ub = *it;
43                        nowy = min(nowy + c, ub - 1);
44                    }
45
46                } else if (d == 1) {
47                    auto it = yob[nowy].upper_bound(nowx);
48                    if (it == yob[nowy].end()) {
49                        nowx += c;
50                    } else {
51                        int ub = *it;
52                        nowx = min(nowx + c, ub - 1);
53                    }
54
55                } else if (d == 2) {
56                    auto lb = xob[nowx].lower_bound(nowy);
57
58                    if (lb != xob[nowx].begin()) {
59                        lb--;
60                        int temp = *lb;
61
62                        if (nowy - c <= temp) {
63                            nowy = temp + 1;
64                        } else {
65                            nowy -= c;
66                        }
67                    } else {
68                        nowy -= c;
69                    }
70
71                } else {
72                    auto lb = yob[nowy].lower_bound(nowx);
73
74                    if (lb != yob[nowy].begin()) {
75                        lb--;
76                        int temp = *lb;
77
78                        if (nowx - c <= temp) {
79                            nowx = temp + 1;
80                        } else {
81                            nowx -= c;
82                        }
83                    } else {
84                        nowx -= c;
85                    }
86                }
87                ans = max(ans, nowx * nowx + nowy * nowy);
88            }
89        }
90        return ans;
91    }
92};
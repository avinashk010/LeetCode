1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4
5        if (grid.size() == 1) {
6            long long total = 0;
7            for (auto x : grid[0])
8                total += x;
9
10            long long pref = 0;
11            for (long long j = 0; j < grid[0].size() - 1; j++) {
12                pref += grid[0][j];
13                long long left = pref;
14                long long right = total - pref;
15                if (left == right)
16                    return true;
17                if (left - grid[0][0] == right)
18                    return true;
19                if (j + 1 < grid[0].size() &&
20                    (left == right - grid[0][j + 1])) {
21                    return true;
22                }
23                if (left - grid[0][j] == right)
24                    return true;
25                if (left == right - grid[0].back())
26                    return true;
27            }
28            return false;
29        }
30
31        if (grid[0].size() == 1) {
32            long long total = 0;
33            for (long long i = 0; i < grid.size(); i++)
34                total += grid[i][0];
35
36            long long pref = 0;
37            for (long long i = 0; i < grid.size() - 1; i++) {
38                pref += grid[i][0];
39                long long left = pref;
40                long long right = total - pref;
41
42                if (left == right)
43                    return true;
44                if (left - grid[0][0] == right)
45                    return true;
46                if (i + 1 < grid.size() && (left == right - grid[i + 1][0])) {
47                    return true;
48                }
49                if (left - grid[i][0] == right)
50                    return true;
51                if (left == right - grid.back()[0])
52                    return true;
53            }
54            return false;
55        }
56
57        long long sum = 0;
58        for (long long i = 0; i < grid.size(); i++) {
59            for (long long j = 0; j < grid[0].size(); j++) {
60                sum += grid[i][j];
61            }
62        }
63
64        set<long long> st;
65        long long temp = 0;
66
67        // top to bottom
68        for (long long i = 0; i < grid.size(); i++) {
69            if (i == 1) {
70                for (long long jj = 0; jj < grid[0].size(); jj++) {
71                    st.insert(grid[0][jj]);
72                }
73            }
74            for (long long j = 0; j < grid[0].size(); j++) {
75                temp += grid[i][j];
76                if (i == 0) {
77                    if (j == 0 || j == grid[0].size() - 1) {
78                        st.insert(grid[i][j]);
79                    }
80                } else {
81                    st.insert(grid[i][j]);
82                }
83            }
84            long long left = sum - temp;
85            if (left == temp)
86                return true;
87            if (left < temp) {
88                auto lb = st.lower_bound(temp - left);
89                if (lb != st.end() && (*lb == (temp - left)))
90                    return true;
91            }
92        }
93
94        st.clear();
95        temp = 0;
96
97        // bottom to top
98        for (long long i = grid.size() - 1; i >= 0; i--) {
99            if (i == grid.size() - 2) {
100                for (long long jj = 0; jj < grid[0].size(); jj++) {
101                    st.insert(grid[grid.size() - 1][jj]);
102                }
103            }
104            for (long long j = 0; j < grid[0].size(); j++) {
105                temp += grid[i][j];
106                if (i == grid.size() - 1) {
107                    if (j == 0 || j == grid[0].size() - 1) {
108                        st.insert(grid[i][j]);
109                    }
110                } else {
111                    st.insert(grid[i][j]);
112                }
113            }
114            long long left = sum - temp;
115            if (left == temp)
116                return true;
117            if (left < temp) {
118                auto lb = st.lower_bound(temp - left);
119                if (lb != st.end() && (*lb == (temp - left)))
120                    return true;
121            }
122        }
123
124        st.clear();
125        temp = 0;
126
127        // left to right
128        for (long long j = 0; j < grid[0].size(); j++) {
129            if (j == 1) {
130                for (long long ii = 0; ii < grid.size(); ii++) {
131                    st.insert(grid[ii][0]);
132                }
133            }
134            for (long long i = 0; i < grid.size(); i++) {
135                temp += grid[i][j];
136                if (j == 0) {
137                    if (i == 0 || i == grid.size() - 1) {
138                        st.insert(grid[i][j]);
139                    }
140                } else {
141                    st.insert(grid[i][j]);
142                }
143            }
144            long long left = sum - temp;
145            if (left == temp)
146                return true;
147            if (left < temp) {
148                auto lb = st.lower_bound(temp - left);
149                if (lb != st.end() && (*lb == (temp - left)))
150                    return true;
151            }
152        }
153
154        st.clear();
155        temp = 0;
156
157        // right to left
158        for (long long j = grid[0].size() - 1; j >= 0; j--) {
159            if (j == grid[0].size() - 2) {
160                for (long long ii = 0; ii < grid.size(); ii++) {
161                    st.insert(grid[ii][grid[0].size() - 1]);
162                }
163            }
164            for (long long i = 0; i < grid.size(); i++) {
165                temp += grid[i][j];
166                if (j == grid[0].size() - 1) {
167                    if (i == 0 || i == grid.size() - 1) {
168                        st.insert(grid[i][j]);
169                    }
170                } else {
171                    st.insert(grid[i][j]);
172                }
173            }
174            long long left = sum - temp;
175            if (left == temp)
176                return true;
177            if (left < temp) {
178                auto lb = st.lower_bound(temp - left);
179                if (lb != st.end() && (*lb == (temp - left)))
180                    return true;
181            }
182        }
183
184        return false;
185    }
186};
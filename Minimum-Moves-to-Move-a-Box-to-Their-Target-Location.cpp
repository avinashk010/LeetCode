1class Solution {
2public:
3    unordered_set<long long> visited;
4
5    // long long encode(int br, int bc, int pr, int pc) {
6    //     return (((((long long)br) * c + bc) * r + pr) * c + pc);
7    // }
8
9    bool possible(int tr, int tc, int fr, int fc, vector<vector<char>>& grid) {
10        if (tr == fr && tc == fc)
11            return true;
12        int r = grid.size();
13        int c = grid[0].size();
14        int dr[4] = {0, -1, 0, +1};
15        int dc[4] = {-1, 0, +1, 0};
16        vector<vector<bool>> vis(r, vector<bool>(c, false));
17        vis[fr][fc] = true;
18        queue<pair<int, int>> q;
19        q.push({fr, fc});
20        while (!q.empty()) {
21            pair<int, int> top = q.front();
22            q.pop();
23
24            for (int i = 0; i < 4; i++) {
25                int nr = top.first + dr[i];
26                int nc = top.second + dc[i];
27
28                if (nr < r && nc < c && nr >= 0 && nc >= 0 &&
29                    grid[nr][nc] == '.' && !vis[nr][nc]) {
30                    if (nr == tr && nc == tc)
31                        return true;
32                    vis[nr][nc] = true;
33                    q.push({nr, nc});
34                }
35            }
36        }
37
38        return false;
39    }
40    long long encode(int br, int bc, int pr, int pc, int r, int c) {
41        return (((((long long)br) * c + bc) * r + pr) * c + pc);
42    }
43
44    int minPushBox(vector<vector<char>>& grid) {
45        visited.clear();
46        int r = grid.size();
47        int c = grid[0].size();
48
49        queue<pair<int, int>> q;
50        int aadr = -1;
51        int aadc = -1;
52
53        int targetr = -1;
54        int targetc = -1;
55
56        int boxatr = -1;
57        int boxatc = -1;
58
59        // vector<vector<bool>>vis(r,vector<bool>(c,false));
60        for (int i = 0; i < r; i++) {
61            for (int j = 0; j < c; j++) {
62                if (grid[i][j] == 'B') {
63                    // vis[i][j] = true;
64                    boxatr = i;
65                    boxatc = j;
66                    grid[i][j] = '.';
67                    q.push({i, j});
68                }
69                if (grid[i][j] == 'S') {
70                    aadr = i;
71                    aadc = j;
72                    grid[i][j] = '.';
73                }
74                if (grid[i][j] == 'T') {
75                    grid[i][j] = '.';
76                    targetr = i;
77                    targetc = j;
78                }
79            }
80        }
81        unordered_map<long long, long long> aadmi;
82        aadmi[(c * boxatr) + boxatc] = ((aadr * c) + aadc);
83        int ans = 0;
84        int dr[4] = {0, -1, 0, +1};
85        int dc[4] = {-1, 0, +1, 0};
86
87        // vis[boxatr][boxatc] = true;
88
89        while (!q.empty()) {
90            int size = q.size();
91            // cout<<size<<endl;
92            for (int x = 0; x < size; x++) {
93
94                pair<int, int> p = q.front();
95                q.pop();
96
97                boxatr = p.first;
98                boxatc = p.second;
99
100                // cout<<boxatr<<" "<<boxatc<<endl;
101
102                aadc = aadmi[boxatr * c + boxatc] % c;
103                aadr = aadmi[boxatr * c + boxatc] / c;
104
105                // long long state = encode(boxatr, boxatc, aadr, aadc, r, c);
106                // if (visited.count(state))
107                //     continue;
108                // visited.insert(state);
109
110                grid[boxatr][boxatc] = 'B';
111
112                for (int i = 0; i < 4; i++) {
113                    int nr = p.first + dr[i];
114                    int nc = p.second + dc[i];
115                    int pr = p.first - dr[i];
116                    int pc = p.second - dc[i];
117
118                    // if(nr == 1 && nc == 1){cout<<pr<<" "<<pc<<" "<<aadr<<"
119                    // "<<aadc;}
120                    // pr 2 pc 3 aadr
121
122                    if (nc >= 0 && nc < c && nr < r && nr >= 0 && pr >= 0 &&
123                        pc >= 0 && pr < r && pc < c && grid[pr][pc] == '.' &&
124                        grid[nr][nc] == '.') {
125
126                        // if(nr == 2 && nc == 1){
127                        //     cout<<pr<<" "<<pc<<" "<<aadr<<" "<<aadc<<endl;
128                        // }
129
130                    
131                        if (possible(pr, pc, aadr, aadc, grid)) {
132
133                            // if(nr == 1 && nc == 1){
134                            //     cout<<"huaaa";
135                            // }
136                            // if(nr == 2 && nc == 1)cout<<pr<<" "<<pc<<endl;
137                            int newManR = boxatr;
138                            int newManC = boxatc;
139
140                            long long newState =
141                                encode(nr, nc, newManR, newManC, r, c);
142                            if (visited.count(newState))
143                                continue;
144
145                            visited.insert(newState);
146                            q.push({nr, nc});
147                            aadmi[nr * c + nc] = newManR * c + newManC;
148
149                            if (nr == targetr && nc == targetc) {
150                                return ans + 1;
151                            }
152                        }
153                    }
154                }
155                grid[boxatr][boxatc] = '.';
156            }
157            ans++;
158        }
159        return -1;
160    }
161};
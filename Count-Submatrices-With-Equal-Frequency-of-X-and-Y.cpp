1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& grid) {
4        vector<vector<pair<int, bool>>> v(
5            grid.size(), vector<pair<int, bool>>(grid[0].size(), {0, false}));
6
7        for (int i = 0; i < grid.size(); i++) {
8            int val = 0;
9            bool x = false;
10            for (int j = 0; j < grid[0].size(); j++) {
11                if (grid[i][j] == 'X') {
12                    x = true;
13                    val++;
14                } else if (grid[i][j] == 'Y') {
15                    val--;
16                }
17                v[i][j] = {val, x};
18            }
19        }
20        int ans = 0;
21        for (int i = 0; i < grid[0].size(); i++) {
22            for (int j = 0; j < grid.size(); j++) {
23
24                if (j) {
25                    v[j][i].first += v[j - 1][i].first;
26                    v[j][i].second = v[j - 1][i].second | v[j][i].second;
27                }
28                if (v[j][i].first == 0 && v[j][i].second)
29                    ans++;
30            }
31            // cout<<endl;
32        }
33        // for (int i = 0; i < grid.size(); i++) {
34        //     for (int j = 0; j < grid[0].size(); j++) {
35        //         cout << v[i][j].first << " " << v[i][j].second << " || ";
36        //     }
37        //     cout << endl;
38        // }
39        return ans;
40    }
41};
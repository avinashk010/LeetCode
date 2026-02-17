1class Solution {
2public:
3    double memo[101][101];
4
5    double solve(int poured , int i , int j) {
6        if (i < 0 || j < 0 || i < j) return 0.0;
7        if (i == 0 && j == 0) return poured;
8        if (memo[i][j] != -1) return memo[i][j];
9
10        double leftUp = (solve(poured , i - 1 , j - 1) - 1) / 2.0;
11        double rightUp = (solve(poured , i - 1 , j) - 1) / 2.0;
12
13        if (leftUp < 0) leftUp = 0.0;
14        if (rightUp < 0) rightUp = 0.0;
15
16        return memo[i][j] = leftUp + rightUp;
17    }
18
19    double champagneTower(int poured, int query_row, int query_glass) {
20        for (int i = 0; i < 101; i++) {
21            for (int j = 0; j < 101; j++) {
22                memo[i][j] = -1;
23            }
24        }
25
26        return min(1.0 , solve(poured , query_row , query_glass));
27    }
28};
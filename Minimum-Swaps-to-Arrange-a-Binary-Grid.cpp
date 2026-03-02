1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n = grid.size();
5        vector<int> zeros(n);
6
7        for (int i = 0; i < n; i++) {
8            int count = 0;
9            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
10            zeros[i] = count;
11        }
12
13        int swaps = 0;
14
15        for (int i = 0; i < n; i++) {
16            int needed = n - i - 1;
17            int j = i;
18            while (j < n && zeros[j] < needed) j++;
19            if (j == n) return -1;
20            while (j > i) {
21                swap(zeros[j], zeros[j - 1]);
22                j--;
23                swaps++;
24            }
25        }
26
27        return swaps;
28    }
29};
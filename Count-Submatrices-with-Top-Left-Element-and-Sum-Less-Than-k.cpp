1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        vector<vector<int>>v(grid.size(), vector<int>(grid[0].size(),0));
5
6
7        for(int i=0; i<grid.size(); i++){
8            for(int j =0; j<grid[0].size(); j++){
9                v[i][j] += grid[i][j];
10                if(j){
11                    v[i][j] += v[i][j-1];
12                }
13            }
14        }
15        int ans = 0;
16        for(int i=0; i<grid[0].size(); i++){
17            for(int j =0; j<grid.size(); j++){
18                
19                    if(j) v[j][i] += v[j-1][i];
20                    if(v[j][i] <= k) ans++;
21              
22            }
23        }
24
25        return ans;
26
27
28    }
29};
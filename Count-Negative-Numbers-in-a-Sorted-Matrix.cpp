1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        int posi = 0;
5        int tot = grid.size()*grid[0].size();
6
7        for(int i =0; i<grid.size();i++){
8            for(int j=0; j<grid[0].size(); j++){
9                if(grid[i][j]>=0) posi++;
10            }
11            if( grid[i][0]<0 ) break;
12        }
13        return tot-posi;
14    }
15};
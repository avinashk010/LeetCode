1class Solution {
2public:
3    int maxi = 0;
4    bool check(int i, int j, int len,vector<vector<int>>&grid){
5        int mainn = 0;
6        for(int x=i ; x<i+len; x++){
7            mainn += grid[x][j];
8        }
9
10        for(int row = i; row < i+len; row++){
11            int now = 0;
12            for(int y = j; y<j+len; y++){
13                now += grid[row][y];
14            }
15            if(now != mainn){
16                return false;
17            }
18        }
19
20        for(int col = j; col < j + len; col++){
21            int now =0;
22            for(int y = i; y < i+len; y++){
23                now += grid[y][col];
24            }
25            if(now != mainn){
26                return false;
27            }
28        }
29        
30        int one = 0;
31        int xx = i;
32        int yy = j;
33        for(int i=0; i<len; i++){
34            one += grid[xx++][yy++];
35        }
36
37        if(one != mainn) return false;
38
39        one = 0;
40        xx = i;
41        yy = j + len-1;
42
43        for(int i=0; i<len; i++){
44            one += grid[xx++][yy--];
45        }
46        if(one != mainn) return false;
47
48        return true;
49    }
50    int largestMagicSquare(vector<vector<int>>& grid) {
51        for(int i =0; i<grid.size(); i++){
52            for(int j  = 0; j<grid[0].size(); j++){
53                int right = grid[0].size()-j;
54                int down = grid.size() - i;
55                for(int len = 1; len<=min(right,down); len++){
56                    bool take = check(i, j, len, grid);
57                    if(take){
58                        maxi = max(maxi, len);
59                    }
60                }
61            }
62        }
63        return maxi;
64    }
65};
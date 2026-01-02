1class Solution {
2public:
3    int numMagicSquaresInside(vector<vector<int>>& grid) {
4        int ans =0;
5        for(int i=0; i<(int)grid.size()-2; i++){
6            for(int j=0; j<(int)grid[0].size()-2; j++){
7                //each
8                set<int>st;
9                vector<bool>check(10,false);
10                bool flag = false;
11
12                for(int x = 0; x<3; x++){
13                    int sum = 0;
14                    int sum2 = 0;
15                    for(int y = 0; y<3; y++ ){
16        
17                        if(grid[x+i][y+j] > 9 || grid[x+i][y+j] == 0){
18                            flag = true;
19                            break;
20                        }
21                        
22                        if(check[grid[x+i][y+j]]){
23                            flag = true;
24                            break;
25                        }
26                        
27                        check[grid[x+i][y+j]] = true;
28                        sum+=grid[x+i][y+j];
29                        sum2+=grid[i+y][j+x];
30                    }
31                    if(flag) break;
32                    st.insert(sum);
33                    st.insert(sum2);
34                }
35                
36                if(flag)continue;
37                int d1 = 0;
38                d1+=grid[i][j];
39                d1+=grid[i+1][j+1];
40                d1+=grid[i+2][j+2];
41                int d2 = 0;
42                d2+=grid[i][j+2];
43                d2+=grid[i+1][j+1];
44                d2+=grid[i+2][j];
45                st.insert(d1);
46                st.insert(d2);
47
48                if(st.size() == 1){
49                    ans++;
50                }
51
52            }
53        }
54        return ans;
55    }
56};
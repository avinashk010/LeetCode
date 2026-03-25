1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
4
5        vector<vector<int>>v(grid.size()-k+1, vector<int>(grid[0].size()-k+1,0));
6        set<int>st;
7        
8        for(int i=0; i<grid.size()-k+1; i++){
9            for(int j =0; j<grid[0].size()-k+1; j++){
10                int ans = INT_MAX;
11                st.clear();
12                for(int ii = i; ii<k+i; ii++){
13                    for(int jj = j; jj<k+j; jj++){
14                        auto lb = st.upper_bound(grid[ii][jj]);
15                        if(lb != st.end()){
16                            ans = min(ans, abs(grid[ii][jj] - *lb));
17                        }
18                        auto up = st.lower_bound(grid[ii][jj]);
19                        if(up != st.begin()){
20                            up--;
21                            ans = min(ans, abs(grid[ii][jj] - *up));
22                        }
23                        st.insert(grid[ii][jj]);
24                    }
25                }
26                if(st.size() == 1){
27                    v[i][j] = 0;
28                }else
29                    v[i][j] = ans;
30            }
31        }
32        return v;
33    }
34};
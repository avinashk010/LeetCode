1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4        set<long long>st;
5        long long sum = 0;
6        for(int i=0; i<grid.size(); i++){
7            for(int j=0; j<grid[0].size(); j++){
8                sum += grid[i][j];
9            }
10            st.insert(sum);
11        }
12        if(sum%2==0 && (st.find(sum/2) != st.end())){
13            return true;
14        }
15       
16        st.clear();
17        sum = 0;
18
19        for(int i=0; i<grid[0].size(); i++){
20            for(int j=0; j<grid.size(); j++){
21                sum += grid[j][i];
22            }
23            st.insert(sum);
24        }
25        
26        if(sum%2==0 && (st.find(sum/2) != st.end())){
27            return true;
28        }
29        return false;
30    }
31};
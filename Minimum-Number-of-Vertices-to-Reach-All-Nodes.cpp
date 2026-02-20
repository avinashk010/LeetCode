1class Solution {
2public:
3    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
4        vector<int>vec(n, 0);
5
6        for(int i=0; i<edges.size(); i++){
7            int u = edges[i][0];
8            int v = edges[i][1];
9
10            vec[v]++;
11        }
12
13        vector<int>ans;
14        for(int i=0; i<n; i++){
15            if(vec[i] == 0){
16                ans.push_back(i);
17            }
18        }
19
20        return ans;
21    }
22};
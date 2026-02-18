1class Solution {
2public:
3
4    void dfs(int n, unordered_map<int,vector<int>>&mp, vector<int>&temp){
5
6        while(mp[n].size()!=0){
7            int val = mp[n].back();
8            mp[n].pop_back();
9            dfs(val,mp,temp);
10        }
11        temp.push_back(n);
12    }   
13    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
14        unordered_map<int,vector<int>>mp;
15        unordered_map<int,int>q;
16
17       
18
19        for(int i =0; i<pairs.size(); i++){
20            mp[pairs[i][0]].push_back(pairs[i][1]);
21            q[pairs[i][0]]++;
22            q[pairs[i][1]]--;
23        }
24
25        int st = -1;
26
27        for(auto e: q){
28            if(e.second > 0){
29                st = e.first;
30            }
31
32           
33        }
34        
35        if(st == -1){
36            st = mp.begin()->first;
37        }
38
39        vector<int>temp;
40        dfs(st,mp,temp);
41
42        reverse(temp.begin(),temp.end());
43        vector<vector<int>>ans;
44
45        for(int i =1; i<temp.size(); i++){
46            ans.push_back({temp[i-1], temp[i]});
47        }
48        
49
50        // ans.push_back(temp);
51
52
53        return ans;
54        
55    }
56};
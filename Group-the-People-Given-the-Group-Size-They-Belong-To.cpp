1class Solution {
2public:
3    vector<vector<int>> groupThePeople(vector<int>& gs) {
4        unordered_map<int,vector<int>>mp;
5
6        for(int i=0; i<gs.size(); i++){
7            mp[gs[i]].push_back(i);
8        }
9
10        vector<vector<int>>ans;
11
12        for(auto& e : mp){
13            auto& v = e.second;
14            int size = v.size();
15            int loop = size/e.first;
16
17            vector<int>temp;
18            for(int i=0; i<v.size(); i++){
19                temp.push_back(v[i]);
20                if(temp.size() == e.first){
21                    ans.push_back(temp);
22                    temp.clear();
23                }
24
25            }
26        }
27
28        return ans;
29    }
30};
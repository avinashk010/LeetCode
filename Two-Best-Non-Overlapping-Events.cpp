1class Solution {
2public:
3    int maxTwoEvents(vector<vector<int>>& events) {
4        map<int,int>mp;
5
6        int maxi = -1;
7        sort(events.begin(),events.end());
8
9        for(int i=events.size()-1; i>=0; i--){
10            maxi = max(maxi, events[i][2]);
11            mp[events[i][0]] = maxi;
12        }
13        int ans = 0;
14        for(int i = 0; i<events.size(); i++){
15            int val = events[i][2];
16            auto it = mp.upper_bound(events[i][1]);
17            if(it != mp.end()){
18                val+= it->second;
19            }
20            ans = max(ans,val);
21        }
22        return ans;
23    }
24
25};
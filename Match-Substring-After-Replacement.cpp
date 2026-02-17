1class Solution {
2public:
3    bool matchReplacement(string& s, string& sub, vector<vector<char>>& mappings) {
4        map<char,unordered_set<char>>mp;
5
6        for(int i=0; i<mappings.size(); i++){
7            mp[mappings[i][0]].insert(mappings[i][1]);
8        }
9
10        for(int i=0; i<s.length()-sub.length()+1; i++){
11            bool ok = true;
12            for(int j =0; j<sub.length(); j++){
13                if(s[i+j] == sub[j]){
14                    continue;
15                }else{
16                    if(mp[sub[j]].find(s[i+j]) != mp[sub[j]].end()){
17                        continue;
18                    }else{
19                        ok = false;
20                        break;
21                    }
22                }
23            }
24            if(ok) return true;
25        }
26        return false;
27    }
28};
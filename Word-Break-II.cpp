1class Solution {
2public:
3    set<string>all;
4    vector<string>ans;
5    void h(int i, string& s, string built){
6        if(i>=s.length()){
7            built.pop_back();
8            ans.push_back(built);
9        }
10
11
12        string now = built;
13        string one = "";
14        for(int x = i; x<s.length(); x++){
15            one+=s[x];
16            if(all.find(one) != all.end()){
17                string to_send = built+one+" ";
18                h(x+1, s, to_send);
19            }
20        }
21
22    }
23
24    vector<string> wordBreak(string s, vector<string>& wordDict) {
25
26        for(auto& s: wordDict){
27            all.insert(s);
28        }
29
30        h(0,s,"");
31        return ans;
32
33    }
34};
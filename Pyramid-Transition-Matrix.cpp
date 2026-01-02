1class Solution {
2public:
3    bool h(string &bottom, string make, unordered_map<char, unordered_map<char, vector<char>>>& m){
4        if(make.length() == bottom.length()-1){
5            if(bottom.size() == 2){
6                return true;
7            }
8            return h(make,"",m);
9        }
10
11        int i = make.size();
12            if( m[bottom[i]].find(bottom[i+1]) != m[bottom[i]].end()){
13                auto &vec = m[bottom[i]][bottom[i+1]];
14                for(int x =0; x<vec.size(); x++){
15                    make+=vec[x];
16                    bool ans = h(bottom,make,m);
17                    if(ans){
18                        return true;
19                    }
20                    make.pop_back();
21                }
22            }
23        
24
25        return false;
26    }
27
28    bool pyramidTransition(string &bottom, vector<string>& allowed) {
29        unordered_map<char, unordered_map<char, vector<char>>>m;
30        for(int i =0; i<allowed.size(); i++){
31            m[allowed[i][0]][allowed[i][1]].push_back(allowed[i][2]);
32        }
33        return h(bottom,"",m);
34    }
35};
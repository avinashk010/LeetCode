1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string &s) {
4        vector<int>vals;
5        vals.push_back(INT_MIN);
6
7        int c =0;
8        int ans =0;
9        for(int i =0; i<s.length(); i++){
10            if(s[i] == '0'){
11                c++;
12            }else{
13                if(c>0)vals.push_back(c);
14                c = 0;
15                ans++;
16            }
17        }
18        if(c>0)vals.push_back(c);
19        vals.push_back(INT_MIN);
20        if(vals.size() == 2){
21            return ans;
22        }
23        int maxi = 0;
24        for(int i=0; i<vals.size()-1; i++){
25            maxi = max(vals[i]+vals[i+1], maxi);
26    
27        }
28        ans += maxi;
29        return ans;
30        
31    }
32};
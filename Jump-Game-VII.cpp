1class Solution {
2public:
3    vector<int>dp;
4    bool h(int i, string& s, int min, int max){
5        if(i+min <= s.length()-1 && i+max >= s.length()-1) return true;
6        if(i == s.length()-1) return true;
7        if(i>=s.length()) return false;
8        
9        if(dp[i] != -1) return dp[i];
10        bool ans = 0;
11       
12            for(int x= min; x<=max; x++){
13                if(i+x<s.length() && s[i+x] == '0'){
14                    bool val = h(i+x, s, min, max);
15                    if(val == true) return dp[i] = true;
16                    // return dp[i] = false;
17                }
18            }
19
20        return dp[i] =  false;
21    }
22    bool canReach(string& s, int minJump, int maxJump) {
23        if(s[s.length()-1] != '0') return false;
24
25        int cnt=0;
26        for(int i = 0; i<s.length(); i++){
27            if(s[i] == '1'){
28                cnt++;
29                if(cnt >= maxJump) return false;
30            }
31            else{
32                cnt = 0;
33            }
34        }
35        
36        dp.assign(s.length(), -1);
37        return h(0,s,minJump, maxJump);
38    }
39};
1class Solution {
2public:
3    string reverseByType(string s) {
4        string normal ="";
5        string two = "";
6
7        for(int i=0; i<s.length(); i++){
8            if(s[i]-'a' >=0 && s[i]-'a' < 26){
9                normal += s[i];
10            }else{
11                two+= s[i];
12            }
13        }
14
15        reverse(normal.begin(),normal.end());
16        reverse(two.begin(),two.end());
17        int o = 0;
18        int j = 0;
19        string ans = "";
20        for(int i=0; i<s.length(); i++){
21            if(s[i]-'a' >=0 && s[i]-'a' < 26){
22                ans+=normal[o++];
23            }else{
24                ans += two[j++];
25            }
26        }
27        return ans;
28    }
29};
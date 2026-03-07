1class Solution {
2public:
3    char findKthBit(int n, int k) {
4        string s = "0";
5
6        for(int i=0; i<n-1; i++){
7            string t = s;
8            for(int x = 0; x<t.length(); x++){
9                if(t[x] == '1'){
10                    t[x] = '0';
11                }else{
12                    t[x] = '1';
13                }
14            }
15            reverse(t.begin(),t.end());
16            s += '1';
17            s+= t;
18            if(s.length() >= k){
19                return s[k-1];
20            }
21        }
22        return '0';
23    }
24};
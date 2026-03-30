1class Solution {
2public:
3    bool checkStrings(string& s1, string& s2) {
4        vector<int>odd(26,0);
5        vector<int>even(26,0);
6        int n = s1.length();
7        for(int i=0; i<n; i++){
8            if(i&1)odd[s1[i] - 'a']++;
9            else even[s1[i] - 'a']++;
10        }
11
12        vector<int>o2(26,0);
13        vector<int>e2(26,0);
14        for(int i=0; i<n; i++){
15            if(i&1)o2[s2[i] - 'a']++;
16            else e2[s2[i] - 'a']++;
17        }
18
19        if(o2 == odd && e2 == even) return true;
20        return false;
21    
22    }
23};
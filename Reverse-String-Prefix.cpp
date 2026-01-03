1class Solution {
2public:
3    string reversePrefix(string s, int k) {
4        string f = s.substr(0,k);
5        string se = s.substr(k);
6        reverse(f.begin(),f.end());
7        return f+se;
8    }
9};
1class Solution {
2public:
3    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
4        set<string>st(bannedWords.begin(),bannedWords.end());
5        int c = 0;
6        for(int i=0; i<message.size(); i++){
7            if(st.find(message[i]) != st.end()){
8                c++;
9                if(c >= 2) return true;
10            }
11        }
12        return false;
13    }
14};
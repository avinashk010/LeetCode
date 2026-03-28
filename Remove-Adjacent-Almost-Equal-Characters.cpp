1class Solution {
2public:
3    int removeAlmostEqualCharacters(string& word) {
4        int ans =0;
5        int i =1;
6        while(i<word.size()){
7            if(word[i] == word[i-1] || word[i] == (word[i-1]-1) || word[i] == (word[i-1]+1)){
8                ans++;
9                i++;
10            }
11            i++;
12        }
13        return ans;
14    }
15};
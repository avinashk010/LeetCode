1class Solution {
2public:
3    int numberOfSpecialChars(string& word) {
4        vector<bool> ans(26, false);
5        vector<bool> lowerf(26, false);
6        vector<bool> upperf(26, false);
7
8        for (int i = 0; i < word.size(); i++) {
9            int ind1 = -1;
10            int ind2 = -1;
11            if(islower(word[i])){
12                ind1 = word[i] - 'a';
13                char x = toupper(word[i]);
14                ind2 = x - 'A';
15            }else{
16                ind2 = word[i] - 'A';
17                char x = tolower(word[i]);
18                ind1 = x - 'a';
19            }
20
21            if (islower(word[i])) { //lower
22                if (upperf[ind2]) {
23                    ans[ind1] = false;
24                    continue;
25                }
26                lowerf[ind1] = true;
27            } else { //upper
28                if (upperf[ind2] == false) {
29                    upperf[ind2] = true;
30
31                    if (lowerf[ind1]) {
32                        ans[ind1] = true;
33                    }
34                }
35            }
36        }
37
38        int f = 0;
39        for (int i = 0; i < 26; i++) {
40            if (ans[i])
41                f++;
42        }
43        return f;
44    }
45};
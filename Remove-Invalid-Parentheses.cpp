1class Solution {
2public:
3    int ans;
4    vector<vector<string>> v;
5    bool correct(string& s) {
6        int change = 0;
7        int c = 0;
8        for (int i = 0; i < s.length(); i++) {
9            if (s[i] == '(') {
10                c++;
11            } else if (s[i] == ')') {
12                c--;
13                if (c < 0) {
14                    return false;
15                }
16            }
17            if (s[i] == '!' || s[i] == '@') {
18                change++;
19            }
20        }
21        if (c == 0) {
22            v[change].push_back(s);
23            return true;
24        }
25        return false;
26    }
27
28    // vector<int>dp;
29
30    long long mini(long long i, string& s) {
31        if (correct(s))
32            return 0;
33        if (i >= s.length())
34            return INT_MAX;
35        
36        // if(dp[i] != -1) return dp[i];
37
38        long long one = INT_MAX;
39
40        if (s[i] == ')' || s[i] == '(') {
41            if (s[i] == ')')
42                s[i] = '@';
43            if (s[i] == '(')
44                s[i] = '!';
45
46            one = 1 + mini(i + 1, s);
47
48            if (s[i] == '!')
49                s[i] = '(';
50            if (s[i] == '@')
51                s[i] = ')';
52        }
53
54        long long two = mini(i + 1, s);
55
56        return min(one, two);
57    }
58    vector<string> removeInvalidParentheses(string& s) {
59        // dp.assign(s.length(),-1);
60        v.assign(26, vector<string>());
61        ans = mini(0, s);
62        // cout<<ans;
63
64        vector<string> last = v[ans];
65
66        unordered_set<string> lastt;
67
68        for (auto st : last) {
69            string clean;
70            for (char ch : st) {
71                if (ch != '!' && ch != '@') {
72                    clean.push_back(ch);
73                }
74            }
75            lastt.insert(clean);
76        }
77
78        return vector(lastt.begin(), lastt.end());
79    }
80};
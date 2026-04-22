1class Solution {
2public:
3    string decodeCiphertext(string& et, int rows) {
4        if(et.length() == 0) return "";
5        vector<string>v;
6
7        int size = et.length() / rows;
8
9        int start = 0;
10
11        for(int i=0; i<rows; i++){
12            v.push_back(et.substr(start, size));
13            start += size; 
14        }
15
16        int i =0;
17        int j =0;
18        int one = 0;
19        string ans = "";
20
21        while(true){
22            if(j >= size) break;
23            if(i<rows && j < size){
24                ans += v[i][j];
25            }
26            i++;j++;
27            if(i == rows){
28                i =0;
29                one++;
30                j = one;
31            }
32        }
33
34        while(ans.back() == ' '){
35            ans.pop_back();
36        }
37
38        return ans;
39    }
40};
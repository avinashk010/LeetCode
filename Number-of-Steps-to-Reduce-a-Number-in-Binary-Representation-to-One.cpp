1class Solution {
2public:
3    int numSteps(string& s) {
4        int ans =0;
5        for(int i=s.length()-1; i>0; i--){
6            if(s[i] == '0'){
7                ans++;
8                continue;
9            }else{
10                int ii = i;
11                ans++;
12                while(ii>=0 && s[ii] == '1'){
13                    // cout<<ii<<endl;
14                    ans++;
15                    ii--;
16                }
17                if(ii < 0){
18                    break;
19                }
20                s[ii] = '1';
21                i = ii+1;
22                // cout<<ans<<" "<<i<<endl;
23            }
24        }
25
26        return ans;
27    }
28
29};
1class Solution {
2public:
3    bool hasAllCodes(string& s, int k) {
4        unordered_set<int>st;
5        
6        for(int i = s.length()-1; i>=0; i--){
7            if(i-k<-1) break;
8            int j =i;
9            int c = 0;
10            int val = 0;
11            while(c < k && j>=0){
12                if(s[j]=='1'){
13                    val += (1<<c);
14                }
15                c++;
16                j--;
17                if(c==k)
18                    st.insert(val);
19            }
20        }
21        
22        // while(st.size()>0){
23        //     cout<<*st.begin();
24        //     st.erase(st.begin());
25        // }
26
27        if(st.size() == 1<<k){
28            return true;
29        }
30        return false;
31    }
32};
1class Solution {
2public:
3    int digArtifacts(int n, vector<vector<int>>& a, vector<vector<int>>& d) {
4        set<pair<int,int>>st;
5        for(auto& v:d){
6            st.insert({v[0],v[1]});
7        }
8
9        int ans =0;
10
11        for(int i=0; i<a.size(); i++){
12            int r1 = a[i][0];
13            int c1 = a[i][1];
14            int r2 = a[i][2];
15            int c2 = a[i][3];
16
17            bool hai = true;
18            for(int x = r1; x<=r2; x++){
19                for(int y = c1; y<=c2; y++){
20                    if(st.find({x,y}) == st.end()){
21                        hai = false;
22                        break;
23                    }
24                }
25                if(!hai) break;
26            }
27            if(!hai) continue;
28            ans++;
29
30        
31            // if(r1 == r2 && c1 == c2){
32            //     if(st.find({r1,c1}) != st.end()){
33            //         ans++;
34            //     }
35            // }else if(r1 == r2-1 && c1 == c2-1){
36            //     if(st.find({r1,c1}) != st.end() && st.find({r1+1,c1}) != st.end() && st.find({r1,c1+1}) != st.end() && st.find({r2,c2}) != st.end()){
37            //         ans++;
38            //     } 
39            // }else{
40            //     if(st.find({r1,c1}) != st.end() && st.find({r2,c2}) != st.end()) ans++;
41            // }
42        }
43
44        return ans;
45    }
46};
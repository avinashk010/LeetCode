1class TopVotedCandidate {
2public:
3
4    int maxi = -1;
5    vector<int>mark;
6    vector<int>ans;
7
8    vector<int>t;
9
10    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
11        mark.assign(persons.size(),0);
12        ans.assign(persons.size(),-1);
13        t = times;
14
15        for(int i=0; i<persons.size(); i++){
16            mark[persons[i]]++;
17            if(mark[persons[i]] >= maxi){
18                maxi = mark[persons[i]];
19                ans[i] = persons[i];
20            }else{
21                ans[i] = ans[i-1];
22            }
23        }
24    }
25    
26    int q(int tt) {
27        
28        auto ub = upper_bound(t.begin(), t.end(), tt);
29        if(ub != t.begin()){
30            ub--;
31            int index = ub - t.begin();
32            return ans[index];
33        }
34        return 0;
35    }
36};
37
38/**
39 * Your TopVotedCandidate object will be instantiated and called as such:
40 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
41 * int param_1 = obj->q(t);
42 */
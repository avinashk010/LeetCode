1class Solution {
2public:
3    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
4        int tot = accumulate(apple.begin(),apple.end(), 0LL);
5
6        sort(capacity.rbegin(),capacity.rend());
7
8        int ans =0;
9        for(int i=0; i<capacity.size(); i++){
10            tot -= capacity[i];
11            ans++;
12            if(tot<=0) break;
13        }
14        return ans;
15    }
16};
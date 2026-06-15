1class Solution {
2public:
3    bool check(long long m, vector<int>& ranks, int cars){
4        long long count = 0;
5        for(long long i =0; i<ranks.size(); i++){
6            long long div = m/ranks[i];
7            if(div>0){
8            long long temp = sqrt(div);
9            count+=temp;}
10        }
11        if(count >= cars) return true;
12        return false;
13    }
14    long long repairCars(vector<int>& ranks, int cars) {
15        long long mini = *min_element(ranks.begin(), ranks.end());
16        long long r = 1LL*cars*cars*mini;
17        long long l = 1;
18
19        long long ans = -1;
20        while(l<=r){
21            long long m = l + (r-l)/2;
22            if(check(m, ranks, cars)){
23                ans = m;
24                r = m-1;
25            }else{
26                l = m+1;
27            }
28        }
29
30        //  long long div = 16/1;
31        //     int temp = sqrt(17);
32        //     cout<<temp;
33
34        return ans;
35    }
36};
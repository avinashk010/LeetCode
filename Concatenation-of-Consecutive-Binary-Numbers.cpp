1class Solution {
2public:
3    static const int mod = 1e9 + 7;
4
5    int concatenatedBinary(int n) {
6        long long ans = 0;
7        int bits = 0;
8
9        for (int i = 1; i <= n; i++) {
10            // if i is power of 2, bit-length increases
11            if ((i & (i - 1)) == 0) bits++;
12
13            ans = ((ans << bits) % mod + i) % mod;
14        }
15
16        return ans;
17    }
18};
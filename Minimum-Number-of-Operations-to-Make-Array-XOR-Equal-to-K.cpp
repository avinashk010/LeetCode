1class Solution {
2public:
3        int minOperations(vector<int>& A, int k) {
4        for (int a : A)
5            k ^= a;
6        return __builtin_popcount(k);
7    }
8};
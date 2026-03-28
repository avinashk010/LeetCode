1class Solution {
2public:
3
4    vector<string>v;
5    // Encodes a URL to a shortened URL.
6    string encode(string longUrl) {
7        v.push_back(longUrl);
8        return to_string(v.size()-1);
9    }
10
11    // Decodes a shortened URL to its original URL.
12    string decode(string shortUrl) {
13        int ind = stoi(shortUrl);
14        return v[ind];
15    }
16};
17
18// Your Solution object will be instantiated and called as such:
19// Solution solution;
20// solution.decode(solution.encode(url));
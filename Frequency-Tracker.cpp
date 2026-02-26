1class FrequencyTracker {
2public:
3    unordered_map<int,int>mp;
4    multiset<int>f;
5    // multiset<int>st;
6    FrequencyTracker() {
7        // st.clear();
8        mp.clear();
9        f.clear();
10    }
11    
12    void add(int number) {
13        mp[number]++;
14        if(f.find(mp[number] - 1) != f.end()){
15            f.erase(f.find(mp[number]-1));
16        }
17        f.insert(mp[number]);
18    }
19    
20    void deleteOne(int number) {
21        if(mp[number] > 0){
22            mp[number]--;
23            // st.erase(st.find(number));
24            
25            if(f.find(mp[number]+1) != f.end()){
26                f.erase(f.find(mp[number]+1));
27            }
28            f.insert(mp[number]);
29        }
30    }
31    
32    bool hasFrequency(int frequency) {
33        if(f.find(frequency) != f.end()) return true;
34        return false;
35    }
36};
37
38/**
39 * Your FrequencyTracker object will be instantiated and called as such:
40 * FrequencyTracker* obj = new FrequencyTracker();
41 * obj->add(number);
42 * obj->deleteOne(number);
43 * bool param_3 = obj->hasFrequency(frequency);
44 */
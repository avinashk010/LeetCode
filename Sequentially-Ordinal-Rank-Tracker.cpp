1class SORTracker {
2public:
3    set<pair<int,string>>st;
4    set<pair<int,string>>::iterator it;
5
6    bool pehla;
7
8    SORTracker() {
9        st.clear();
10        it = st.end();
11        pehla = true;
12    }
13    
14    void add(string name, int score) {
15        pair<int,string> ti = {-score,name};
16        st.insert(ti);
17        if(it == st.end()){
18            if(pehla){
19                it = st.begin();
20                pehla = false;
21            }else{
22                it--;
23            }
24        }else{
25            if(ti < *it){
26                it--;
27            }
28        //    ' int hscore = -((*it).first);
29        //     string hstring = (*it).second;
30
31        //     if(-(ti.first) > hscore){
32        //         it--;
33        //     }else if(hscore < -(ti.first)){
34
35        //     }else{
36        //         if(ti.second < hstring){
37        //             it--;
38        //         }
39        //     }
40        }
41    }
42    
43    string get() {
44        string ans = it->second;
45        it++;
46        // advance(it,1);
47        return ans;
48    }
49};
50
51/**
52 * Your SORTracker object will be instantiated and called as such:
53 * SORTracker* obj = new SORTracker();
54 * obj->add(name,score);
55 * string param_2 = obj->get();
56 */
1class LRUCache {
2public:
3    struct Node {
4        int key;
5        int val;
6        Node* next;
7        Node* prev;
8        Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {};
9    };
10
11    int size;
12    unordered_map<int, Node*> mp;
13    Node* head;
14    Node* tail;
15
16    LRUCache(int capacity) {
17        size = capacity;
18        head = new Node(-1, -1);
19        tail = new Node(-1, -1);
20        head->next = tail;
21        tail->prev = head;
22    }
23
24    void del(Node* curr) {
25        Node* aage = curr->next;
26        Node* piche = curr->prev;
27
28        aage->prev = piche;
29        piche->next = aage;
30    }
31
32    void insert(Node* curr) {
33        Node* temp = head->next;
34        head->next = curr;
35        curr->next = temp;
36        temp->prev = curr;
37        curr->prev = head;
38    }
39
40    int get(int key) {
41        if (mp.find(key) == mp.end())
42            return -1;
43
44        Node* temp = mp[key];
45        del(temp);
46        insert(temp);
47
48        return temp->val;
49    }
50
51    void put(int key, int value) {
52
53        if (mp.find(key) != mp.end()) {
54            del(mp[key]);
55            mp.erase(key);
56        } else {
57            if (mp.size() >= size) {
58                mp.erase(tail->prev->key);
59                del(tail->prev);
60            }
61        }
62        Node* temp = new Node(key, value);
63        mp[key] = temp;
64        insert(temp);
65    }
66};
67
68/**
69 * Your LRUCache object will be instantiated and called as such:
70 * LRUCache* obj = new LRUCache(capacity);
71 * int param_1 = obj->get(key);
72 * obj->put(key,value);
73 */
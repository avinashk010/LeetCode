1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    int pairSum(ListNode* head) {
14        ListNode* slow = head;
15        ListNode* fast = head;
16
17        ListNode* prev = NULL;
18        ListNode* abhi = head;
19        ListNode* aage = head->next;
20
21        while(fast->next->next != NULL){
22            
23            slow = slow->next;
24
25
26            fast = fast->next;
27            fast = fast->next;
28
29            abhi->next = prev;
30            prev = abhi;
31            abhi = aage;
32            aage = aage->next;
33        }
34
35        int ans =0;
36        slow = slow->next;
37        abhi->next = prev;
38        while(slow != NULL){
39            ans = max(ans, slow->val+abhi->val);
40            // cout<<abhi->val;
41            // cout<<slow->val;
42            slow = slow->next;
43            abhi = abhi->next;
44        }
45
46        return ans;
47    }
48};
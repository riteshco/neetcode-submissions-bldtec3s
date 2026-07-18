/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i=0; i<n; i++) {
            if(lists[i] != nullptr) pq.push({lists[i]->val, lists[i]});
        }
        ListNode dummy(-1);
        ListNode* tmp = &dummy;
        while(!pq.empty()) {
            ListNode* node = pq.top().second;
            pq.pop();
            tmp->next = node;
            tmp = tmp->next;
            if(node->next) pq.push({node->next->val, node->next});
        }
        return dummy.next;
    }
};

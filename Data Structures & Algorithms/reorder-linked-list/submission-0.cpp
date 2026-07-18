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
    void reorderList(ListNode* head) {
        unordered_map<ListNode*, bool> seen;
        ListNode* curr = head;
        while(curr->next) {
            ListNode* temp = curr;
            ListNode* tempPlusOne = temp->next;
            if(seen.find(tempPlusOne) != seen.end()) {
                temp->next = nullptr;
                break;
            }
            while(temp->next && seen.find(temp->next) == seen.end()) temp = temp->next;
            curr->next = temp;
            temp->next = tempPlusOne;
            seen[temp] = true;
            curr = temp->next;
        }
    }
};

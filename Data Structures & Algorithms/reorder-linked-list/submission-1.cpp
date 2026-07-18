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
private:
    ListNode* recurse(ListNode* curr, ListNode* currEnd) {
        if(currEnd == nullptr) return curr;
        curr = recurse(curr, currEnd->next);
        if(curr == nullptr) return curr;
        if(curr == currEnd || curr->next == currEnd) {
            currEnd->next = nullptr;
            return nullptr;
        } else {
            currEnd->next = curr->next;
            curr->next = currEnd;
            return currEnd->next;
        }
    }
public:
    void reorderList(ListNode* head) {
        head = recurse(head, head->next);

        // unordered_map<ListNode*, bool> seen;
        // ListNode* curr = head;
        // while(curr->next) {
        //     ListNode* temp = curr;
        //     ListNode* tempPlusOne = temp->next;
        //     if(seen.find(tempPlusOne) != seen.end()) {
        //         temp->next = nullptr;
        //         break;
        //     }
        //     while(temp->next && seen.find(temp->next) == seen.end()) temp = temp->next;
        //     curr->next = temp;
        //     temp->next = tempPlusOne;
        //     seen[temp] = true;
        //     curr = temp->next;
        // }
    }
};

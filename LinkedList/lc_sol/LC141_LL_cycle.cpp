/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* mover = head;
        ListNode* temp = NULL;
        while(mover!=NULL){
            if(mover->next == head) return true;
            temp = mover->next;
            mover->next = head;
            mover = temp;
        }
        return false;
    }
};
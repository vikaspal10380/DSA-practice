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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right){
            return head;
        }
        ListNode* Dummy = new ListNode(0);
        Dummy->next = head;
        ListNode* prev = Dummy;

        for(int i=1; i<left; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* rev = nullptr;

        for(int i=0; i<=right-left; i++){
            ListNode* temp = curr->next;
            curr->next = rev;
            rev = curr;
            curr = temp;
        }
        ListNode* first = prev->next;
        prev->next = rev;
        first->next = curr;

        return Dummy->next;
    }
};
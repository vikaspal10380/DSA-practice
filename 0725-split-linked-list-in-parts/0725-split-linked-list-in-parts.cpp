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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;

        while(temp){
            len++;
            temp=temp->next;
        }
        int size = len/k;
        int extra = len%k;

        vector<ListNode*> ans;

        for(int i=0; i<k; i++){
            ans.push_back(head);

            int partSize = size;

            if(extra > 0){
                partSize++;
                extra--;
            }
            for(int j=1; j<partSize && head; j++){
                head = head->next;
            }
            if(head){
                ListNode* next = head->next;
                head->next = NULL;
                head = next;
            }
        }
        return ans;
    }
};
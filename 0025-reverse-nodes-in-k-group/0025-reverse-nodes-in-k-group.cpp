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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        
        ListNode* fh = new ListNode(0, head);
        ListNode* bp = fh, *bc = head;
        int i=0;
        while(bc && i+k<=n){
            int j=0;
            ListNode* curr = bc, *prev = NULL;
            while(j<k && curr){
                j++;
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            bp->next = prev;
            bp = bc;
            bc->next = curr;
            bc = curr;
            i+=k;
        }
        return fh->next;
    }
};
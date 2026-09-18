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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0);
        ans.next = head;

        ListNode* prev = &ans;
        ListNode* curr = head;

        while(curr){
            int fl = 0;

            while(curr->next && curr->val == curr->next->val){
                fl = 1;
                curr = curr->next;
            }

            if(fl)
                prev->next = curr->next;
            else
                prev = prev->next;

            curr = curr->next;
        }

        return ans.next;
    }
};
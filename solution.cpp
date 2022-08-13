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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p1 = dummy;
        if(head == NULL || head->next == NULL) {
            return head;
        }
        if(head->next->next == NULL) {
            if(head->val == head->next->val) {
                return NULL;
            }
            return head;
        }
        while(p1 != NULL && p1->next != NULL && p1->next->next != NULL && p1->next->next->next != NULL) {
            if(p1->next->val == p1->next->next->val && p1->next->next->next->val == p1->next->val) {
                p1->next->next = p1->next->next->next;
            }
            else if(p1->next->val == p1->next->next->val) {
                p1->next = p1->next->next->next;
            }
            else {
                p1 = p1->next;
            }
        }
        if(p1->next != NULL && p1->next->next != NULL) {
            if(p1->next->val == p1->next->next->val) {
                p1->next = NULL;
            }
        }
        return dummy->next;
    }
};

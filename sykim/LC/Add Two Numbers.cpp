/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cmath>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* base = new ListNode(0);
        ListNode* movePtr;

        movePtr = base;
        int pass_val = 0;
        
        while (true)
        {
            // Calculate the current value;
            int cur_val = l1->val + l2->val;

            // Calculate the current value and value to pass.
            pass_val = cur_val / 10;
            cur_val = cur_val % 10;
            
            // If a value to pass and the current value is 0,
            // and at the same time, the next nodes of l1 and l2 are NULL,
            // we can assume there are no nodes to consider anymore.
            if (pass_val == 0 && cur_val == 0
                && l1->next == NULL && l2->next == NULL)
            {
                // If just the next of the base is NULL,
                // we can figure out there are no node in the base link,
                // so let's create a node which has a value 0.
                if (base->next == NULL)
                {
                    ListNode* dummy = new ListNode(0);
                    base->next = dummy;
                }
                break;
            }
            
            // After create a dummy node, assign a value to it,
            // and link it to the current node.
            ListNode* dummy = new ListNode(0);
            dummy->val = cur_val;
            movePtr->next = dummy;
            
            // To simplify the consideration of the next node,
            // let's just create the next node :).
            if (l1->next == NULL)
            {
                ListNode* nextDummy = new ListNode(0);
                l1->next = nextDummy;
            }
            if (l2->next == NULL)
            {
                ListNode* nextDummy = new ListNode(0);
                l2->next = nextDummy;
            }
            
            // If there is a value to pass to the next, we count it.
            if (pass_val)
            {
                l1->next->val += 1;
                pass_val = 0;
            }
            
            // Move to the next node.
            l1 = l1->next;
            l2 = l2->next;
            movePtr = movePtr->next;
        }
        
        return base->next;
    }
};

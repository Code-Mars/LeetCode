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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int last=-1,len=0, count = 0, mx = -1, mn = -1;
        ListNode* prev = NULL, *next = head;
        while (head) {
            next = head->next;
            if(last!=-1)count++, len++;
            if (prev and next) {
                if ((prev->val < head->val and next->val < head->val) or
                    (prev->val > head->val and next->val > head->val)) {
                        if(last!=-1){

                            mn=min(count, mn==-1?(int)1e9:mn);
                            mx=max(mx, len);
                            count=0;
                        }

                        last=1;
                }
            }
            prev=head;
            head=next;
        }
        return {mn, mx};
    }
};
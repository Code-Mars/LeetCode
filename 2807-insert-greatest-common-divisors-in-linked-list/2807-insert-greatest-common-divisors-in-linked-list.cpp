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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev=head, *cur=head->next, *next;
        if(!cur)return head;
        while(cur){
            auto node=new ListNode(__gcd(prev->val, cur->val));
            prev->next=node;
            node->next=cur;
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};
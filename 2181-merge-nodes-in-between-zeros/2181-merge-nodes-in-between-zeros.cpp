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
    ListNode* ans=NULL;
    void solve(ListNode* head){
        if(!head)return;
        solve(head->next);
        if(head->val)ans->val+=head->val;
        else ans=new ListNode(0, ans);
    }
    ListNode* mergeNodes(ListNode* head) {
        solve(head);
        return ans->next;
    }
};
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
    pair<ListNode*, int>dfs(ListNode* head){
        if(!head)return {NULL, 0};
        auto node=dfs(head->next);
        int x=head->val*2+node.second;
        head->val=x%10;
        return {head, x/10};
    }
    ListNode* doubleIt(ListNode* head) {
        auto ans=dfs(head);
        if(ans.second>0){
            return new ListNode(ans.second, ans.first);
        }
        return ans.first;
    }
};
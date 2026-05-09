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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return head;
        while(head->val==val && head->next!=nullptr){
            head->val = head->next->val;
            head->next = head->next->next;
        }
        ListNode* temp = head;
        while(temp->next!=nullptr){
            if(temp->next->val == val){
                temp->next = temp->next->next;
            } else {
                temp=temp->next;
            }
        }
        if(temp->val==val)
            return nullptr;
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> checked;
        if(head==nullptr)
            return head;
        ListNode* temp=head;
        
        while(temp){
            if(checked.find(temp)!=checked.end()){
                return temp;
            }
            checked[temp] = 1;
            temp=temp->next; 
        }
        return nullptr;
    }
};
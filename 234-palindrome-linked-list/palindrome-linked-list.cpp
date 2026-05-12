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
    bool isPalindrome(ListNode* head) {
        stack<int> check;
        ListNode* temp = head;
        while(temp){
            check.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val!=check.top())
                return false;
            check.pop();
            temp=temp->next;
        }
        return true;
    }
};
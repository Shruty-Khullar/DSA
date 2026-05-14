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
    ListNode* reverse(ListNode* tempHead){
        if(tempHead==nullptr || tempHead->next==nullptr)
            return tempHead;
        ListNode* currHead = reverse(tempHead->next);
        ListNode* front = tempHead->next;
        front->next = tempHead;
        tempHead->next=nullptr;
        return currHead;
    }
    bool isPalindrome(ListNode* head) {
        // stack<int> check;
        // ListNode* temp = head;
        // while(temp){
        //     check.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp){
        //     if(temp->val!=check.top())
        //         return false;
        //     check.pop();
        //     temp=temp->next;
        // }
        // return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHead = reverse(slow->next);
        slow=head;
        fast=secondHead;
        while(slow && fast){
            if(slow->val!=fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
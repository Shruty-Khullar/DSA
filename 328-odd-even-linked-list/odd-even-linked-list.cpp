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
    ListNode* oddEvenList(ListNode* head) {
        // if(head==nullptr)
        //     return head;
        // queue<int> odd;
        // queue<int> even;
        // ListNode* temp = head;
        // int oddCount=1;
        // while(temp){
        //     if(oddCount%2!=0){
        //         odd.push(temp->val);
        //         oddCount++;
        //     } else {
        //         even.push(temp->val);
        //         oddCount++;
        //     }
        //     temp=temp->next;
        // }
        // temp=head;
        // while(odd.size()>0){
        //     temp->val = odd.front();
        //     odd.pop();
        //     temp=temp->next;
        // }
        // while(even.size()>0){
        //     temp->val = even.front();
        //     even.pop();
        //     temp=temp->next;
        // }
        // return head;
        if(head==nullptr)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while(odd && odd->next && even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next = evenHead;
        return head;

    }
};
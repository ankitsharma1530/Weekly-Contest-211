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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr)
            return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(left > 1){
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* conn = prev;
        ListNode* tail = curr;
        
        while(right > 0){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            right--;
        }
         if(conn != nullptr){
             conn->next = prev;
         }else{
             head = prev;
         }
        tail->next = curr;
        return head;
    }
};

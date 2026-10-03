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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* current = head;

        while(current){
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        secondHalf = reverseList(secondHalf);

        ListNode dummy;
        ListNode* current = &dummy;
        while(head && secondHalf){
            current->next = head;
            head = head->next;
            current = current->next;

            current->next = secondHalf;
            secondHalf = secondHalf->next;
            current = current->next;
        }
        if(head){
            current->next = head;
        }
        else{
            current->next = secondHalf;
        }
    }
};

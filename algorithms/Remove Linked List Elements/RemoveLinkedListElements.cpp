/*
Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 
*/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(val-1),*cur,*prev = &dummy;
        dummy.next = head;
        cur = prev->next;
        while(cur){
            if(cur->val != val){
                prev = cur;
                cur = cur->next;
            }else{
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
        }
        return dummy.next;
    }
};
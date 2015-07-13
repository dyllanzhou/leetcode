/*Palindrome Linked List 
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    int count(ListNode* h){
        int sum = 0;
        while(h){
            sum++;
            h = h->next;
        }
        return sum;
    }
    ListNode* reverse(ListNode* h){
        ListNode*next, *nh = NULL;
        while(h){
            next = h->next;
            h->next = nh;
            nh = h;
            h = next;
        }
        return nh;
    }
    bool isPalindrome(ListNode* head) { //1,2
         ListNode* p = head;
         int cnt = count(head);
         p = head;
         for(int i = 0;i < cnt/2;i++,p = p->next);
         if(cnt%2 && p)p = p->next;
         p = reverse(p);
         while(p){
             if(p->val != head->val)break;
             p = p->next;
             head = head->next;
         }
         return !p;
    }
};
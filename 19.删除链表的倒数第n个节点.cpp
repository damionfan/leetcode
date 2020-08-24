/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p = head;
    ListNode* q = head;
    ListNode* r;
    while(n>0){
        n--;
        q=q->next;
    } 
    if(q==NULL) return head->next;

    while(q){
        q = q->next;
        r = p;
        p = p->next;

    }
    r->next = p->next;

    return head;
    }
};
// @lc code=end


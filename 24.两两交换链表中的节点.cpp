/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = head;
        if(head==NULL) return head;
        ListNode* q = head->next;
        
        if (q==NULL) return head;
        //q = p->next;
        head = q;
        p->next = q->next;
        q->next = p;
        
        ListNode* pre = p;
        p = p->next;
        while(p&&p->next){
            q = p->next;
            p->next = q->next;
            q->next = p;
            if (pre!=NULL) pre->next = q;
            pre = p;
            p = p->next;

        }
        return head;
    }
};
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;

        ListNode* pre = head->next;
        head->next = pre->next;
        pre->next = head;
        head->next = swapPairs(head->next);
        return pre;

    }
};

// @lc code=end


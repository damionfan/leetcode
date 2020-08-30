/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val<l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }else
        {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
        
    }
};

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode();
        ListNode* q = p;
        while(l1){
            if(l2==NULL) break;
            if (l1->val<l2->val){
                p->next = l1;
                l1=l1->next;
                p = p->next;
                p->next=NULL;
            }else{
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                p->next = NULL;
            }
        }
        if (l1==NULL) p->next=l2;
        if(l2==NULL) p->next = l1;

        return q->next;
    }
};
*/
// @lc code=end


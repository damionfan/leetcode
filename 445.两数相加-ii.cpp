/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = new ListNode;
        ListNode* q;
        while(l1){
            q= l1->next;
            l1->next = p->next;
            p->next = l1;
            l1 = q;
        }
        l1 = p->next;
        p->next = NULL;
        while(l2){
            q = l2->next;
            l2->next = p->next;
            p->next = l2;
            l2 = q;
        }
        l2 = p->next;
        p->next = NULL;
        auto flag = 0.; 

        ListNode* head = p;
        while(l1&&l2){
            ListNode* temp = new ListNode;
            temp->val = l1->val+l2->val+flag;
            if (temp->val>=10){
                flag = temp->val/10;
                temp->val = temp->val%10;
            }else
            {
                flag = 0;
            }
            
            p->next = temp;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            while(l1){
                ListNode* temp = new ListNode;
                temp->val = l1->val+flag;
                if (temp->val>=10){
                    flag = temp->val/10;
                    temp->val = temp->val%10;
                }else
                {
                    flag = 0;
                }
                
                p->next = temp;
                p = p->next;
                l1 = l1->next;
            }
        }

        if(l2){
            while(l2){
                ListNode* temp = new ListNode;
                temp->val = l2->val+flag;
                if (temp->val>=10){
                    flag = temp->val/10;
                    temp->val = temp->val%10;
                }else
                {
                    flag = 0;
                }
                
                p->next = temp;
                p = p->next;
                l2 = l2->next;
            }
        }

        if(flag>0){
            ListNode* temp = new ListNode;
            temp->val = flag;
            p->next = temp;
        }
        ListNode* m = new ListNode;
        ListNode* n = m;
        head = head->next;
        while(head){
            n = head->next;
            head->next = m->next;
            m->next = head;
            head = n;
        }
        return m->next;
    }
};
*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }    
        ListNode* head = new ListNode;
        ListNode* p = head;
        auto carry = 0;
        while(!s1.empty()||!s2.empty()||carry!=0){
            auto a = s1.empty()?0:s1.top();
            auto b = s2.empty()?0:s2.top();
            
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();

            auto cur = a+b+carry;
            carry = cur/10;
            ListNode* temp = new ListNode(cur%10);
            temp->next = p->next;
            p->next = temp; 
        }

        return head->next;
    }
};



// @lc code=end


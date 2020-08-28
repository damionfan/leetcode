/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* p1 = new ListNode;
        ListNode* p2 = p1;
        ListNode* q1 = new ListNode;
        ListNode* q2 = q1;

        if (head==nullptr||head->next==nullptr) return head;

        auto flag = 1;
        ListNode* temp;

        while (head)
        {
            if(flag%2==0){
                temp = head->next;
                head->next = nullptr;
                q2->next = head;
                q2 = q2->next;
                head = temp;
            }else
            {
                temp = head->next;
                head->next = nullptr;
                p2->next = head;
                p2 = p2->next;
                head = temp;
            }
            
            flag +=1;
        }

        p2->next = q1->next;

        return p1->next;
    }
};
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode*  evenhead = even;
        while(even&&even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenhead;

        return head;
    }
};

// @lc code=end


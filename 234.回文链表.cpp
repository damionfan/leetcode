/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        
        stack<int> s;
        ListNode* p =head;
        
        
        while (p)
        {
            s.push(p->val);
            p = p->next;
        }
        while(head){
            if(head->val == s.top()){
                s.pop();
            }else
            {
                return false;
            }

            head = head->next;
            
        }

        return s.empty();

    }
};
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pre = new ListNode;
        ListNode* curr = slow;
        ListNode* temp;

        while(curr){
            temp = curr->next;
            curr->next = pre->next;
            pre->next = curr;
            curr = temp;
        }
        curr = pre->next;
        while(curr){
            if(head->val == curr->val){
                head = head->next;
                curr = curr->next;
            }else
            {
                return false;
            }
            

        }

        return true;
    }
};
// @lc code=end

/*
主要是两个思路一个是堆栈反转。判断‘
方法二使用快慢指针然后进行反转。当快指针到达最后的时候，满指针在中间。

*/

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* p;
    p = head;
    while(p&&p->next){
        
        if (p->next->val == p->val){
            p->next = p->next->next;
        }else
        {
            p = p->next;
        }
            
            
    }
    return head;    
    }
};
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if (head==NULL||head->next==NULL) return head;
    head->next = deleteDuplicates(head->next);
    
    return (head->val == head->next->val)?head->next:head;
    }
};

// @lc code=end
/*
方法一：使用一个指针指向头节点，如果下一个节点存在并且与改节点相等的话，则使得p->next = p->next->next
否则如果不相等，则指针向下移动。

方法二：递归方法
终止条件：当前为空节点或者为最后一个节点的时候，返回改节点
赋值：当前节点的下一个节点为返回节点
返回：如果当前节点的值和下一个节点的值相等的话，返回下一个节点；否则返回当前节点。
*/

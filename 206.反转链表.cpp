/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
头插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * p = new ListNode;
        ListNode * q = new ListNode;
        while(head){
            p = q->next;
            q->next = head;
            head = head->next;
            q->next->next = p;
        }
        return q->next;
    }
};
*/
//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL||head->next == NULL){
            return head;
        }
        ListNode *next = head->next;
        ListNode *newhead = reverseList(next);
        next->next = head;
        head->next=NULL;
        return newhead;
    }
};

/*
头插法就是新建一个头节点，然后旧的头节点一直向后遍历
并且直接插到新头的后面，值得注意的是需要一个指针提前
保存新头的next

递归法就是不断的递归一直到最后一个元素，然后将返回的元
素放置在新头上面，然后新头的第一个节点就保证是最后一个
节点。然后，这次迭代的节点就是最后一个节点，然后将传入
的节点插入到后面，并且置空。

在这里值得注意的是，或操作||是进行判断如果两个有一个成
立，那么就一个成立。如果第一个或条件成立了，那么后面的
或条件就不会被访问了。

这样就满足了，如果出现第一个列表为空的时候，那么访问它的next
的时候就会出现错误了。

*/
// @lc code=end


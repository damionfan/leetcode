/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * l1   = headA;
        ListNode * l2   = headB;
        while (l1!=l2)
        {
            l1 = (l1==NULL)?headB:l1->next;
            l2 = (l2==NULL)?headA:l2->next;
            /* code */
        }
        
        return l1;
    }
};
// @lc code=end

/*
时间：2020-08-20
题目解析:这个题目是需要判断两个链表的交点，所谓的交点就是在这个节点的地方两个
列表相遇了，即，他们的同时指向了同一个节点。不仅仅是节点的数据相同而且他们的
地址也是相同的。

如何做这个题目呢？
根据解题指南中给的题目我们可以的到，对于链表A的长度可以设为a+c，a是A还没有相交的时候的长度。
那么同样的链表B的长度可以设置为b+c
这样的话就可以得到a+c+b=b+c+a也就是说，如果在每次两个链表同时向前访问的话。并且同时在访问结束的时候指向另外一个链表的头，这样的话就可以同时访问到交点。
然而，如果没有交点的话，两个指针同时访问到了，两个链表的尾部，也就是两个指针均为空。

这道题目主要考察了对于链表的特性的基本使用情况。
-----------------
*/
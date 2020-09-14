/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxdep = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxdep;
    }

    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        int leftdepth = depth(root->left);
        int rightdepth = depth(root->right);
        maxdep = max(leftdepth+rightdepth,maxdep);
        return max(leftdepth,rightdepth)+1;
    }
};
// @lc code=end


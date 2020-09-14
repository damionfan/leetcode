/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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

/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root==nullptr){
            return true;
        } 
        else
        {
            return abs(depth(root->left)-depth(root->right)) <= 1 && isBalanced(root->left)&&isBalanced(root->right);

        }
        
    }

    int depth(TreeNode* root){
        if(root == nullptr) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) >= 0;
    }

    int depth(TreeNode* root){
        if(root==nullptr) return 0;
        int leftdepth = depth(root->left);
        int rightdepth = depth(root->right);
        if(leftdepth ==-1||rightdepth == -1|| abs(leftdepth-rightdepth)>1)
            return -1;
        return max(leftdepth,rightdepth)+1;
    }

};
// @lc code=end


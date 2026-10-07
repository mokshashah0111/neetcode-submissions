/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int helper(TreeNode* root, int currMax){
        if(!root) return 0;
        int isGood = root->val >= currMax ? 1 : 0;
        currMax = max(currMax, root->val);
        int leftNodes = helper(root->left, currMax);
        int rightNodes = helper(root->right, currMax);
        return isGood + leftNodes + rightNodes;
    }
public:
    int goodNodes(TreeNode* root) {
        int currMax = INT_MIN;
        return helper(root, currMax);
    }
};

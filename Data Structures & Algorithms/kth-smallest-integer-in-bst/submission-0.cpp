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
public:
    void dfs(TreeNode* root, int& count, int& nodeValue){
        if(!root) return;
        dfs(root->left, count,nodeValue);
        count--;
        if(count==0)nodeValue = root->val;
        dfs(root->right, count,nodeValue);
    }
    int kthSmallest(TreeNode* root, int k) {
        int nodeValue = -1;
        dfs(root,k,nodeValue);
        return nodeValue;
    }
};

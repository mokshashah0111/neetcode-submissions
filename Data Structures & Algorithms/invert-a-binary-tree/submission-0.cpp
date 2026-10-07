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
    void Inversion(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right)return;
        auto temp = root->left ? root->left : nullptr;
        root->left = root->right ? root->right : nullptr;
        root->right = temp;
        Inversion(root->left);
        Inversion(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        Inversion(root);
        return root;
    }
};

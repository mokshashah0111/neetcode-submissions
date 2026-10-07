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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        vector<int>result;
        while(!q.empty()){
            int currSize = q.front().second;
            int lastValue = -1;
            while(q.front().second == currSize){
                auto node =q.front().first;
                q.pop();
                if(node->left){
                    q.push({node->left,currSize+1});
                }
                if(node->right){
                    q.push({node->right,currSize+1});
                }
                lastValue = node->val;
            }
            result.emplace_back(lastValue);
        }
        return result;
    }
};

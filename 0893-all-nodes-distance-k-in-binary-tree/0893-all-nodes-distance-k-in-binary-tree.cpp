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
private:
    int helper(TreeNode* node, TreeNode* &target, vector<int> &ans, int dist){
        if(!node) return -1;
        if(node==target){
            miniHelper(node->left, ans, dist-1);
            miniHelper(node->right, ans, dist-1);
            return dist-1;
        }
        int tempL = helper(node->left, target, ans, dist);
        if(tempL!=-1){
            if(!tempL){
                ans.push_back(node->val);
                return -1;
            }
            miniHelper(node->right, ans, tempL-1);
            return tempL-1;
        }
        int tempR = helper(node->right, target, ans, dist);
        if(tempR!=-1){
            if(!tempR){
                ans.push_back(node->val);
                return -1;
            }
            miniHelper(node->left, ans, tempR-1);
            return tempR-1;
        }
        return -1;
    }
    void miniHelper(TreeNode* node, vector<int> &ans, int dist){
        if(!node) return;
        if(!dist){
            ans.push_back(node->val);
            return;
        }
        miniHelper(node->left, ans, dist-1);
        miniHelper(node->right, ans, dist-1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!k) return {target->val};
        vector<int> ans;
        helper(root, target, ans, k);
        return ans;
    }
};
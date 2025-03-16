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
    int widthOfBinaryTree(TreeNode* root) {
        queue< pair<TreeNode*, long long> > queue;
        queue.push({root,1});
        long long ans = 0;
        while (!queue.empty()) {
            int currentLength = queue.size();
            long long startVal = queue.front().second;
            long long endVal = queue.back().second;
            ans = max(ans, endVal - startVal + 1);
            
            for (int i = 0; i < currentLength; i++) {
                auto p = queue.front();
                queue.pop();
                TreeNode* node = p.first;
                long long val = p.second - startVal;
                if (node->left != nullptr) {
                    queue.push({node->left, 2*val});
                }
                if (node->right != nullptr) {
                    queue.push({node->right, (2*val)+1});
                }
            }
        }
        return ans;
    }
};
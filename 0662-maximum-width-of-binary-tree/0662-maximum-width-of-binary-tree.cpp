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
        queue< pair<TreeNode*, unsigned long long int> > queue;
        queue.push({root,1});
        unsigned long long int ans = 0;
        while (!queue.empty()) {
            int currentLength = queue.size();
            unsigned long long int mn = ULLONG_MAX, mx = 0;
            for (int i = 0; i < currentLength; i++) {
                auto p = queue.front();
                queue.pop();
                TreeNode* node = p.first;
                unsigned long long int val = p.second;
                if (node->left != nullptr) {
                    queue.push({node->left, 2*val});
                }
                if (node->right != nullptr) {
                    queue.push({node->right, (2*val)+1});
                }
                mx = max(mx, val);
                mn = min(mn, val);
            }
            ans = max(ans, mx-mn+1);
        }
        return ans;
    }
};
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
    // I didn't know I could add functions to the solutions
    // still in doubt if I should name my variables in english or portuguese, I guess it doesn't matter
    void solve(TreeNode* root, int& previous, int& minimum){
        if(!root)
            return;
        solve(root->left, previous, minimum);
        if(previous != -1){
            minimum = min(minimum, abs(root->val - previous));
        }
        previous = root->val;
        solve(root->right, previous, minimum);
    }

    int getMinimumDifference(TreeNode* root) {
        // in order traversel of BST
        int minimum = INT_MAX;
        int previous = -1;
        solve(root, previous, minimum);
        return minimum;
    }
};

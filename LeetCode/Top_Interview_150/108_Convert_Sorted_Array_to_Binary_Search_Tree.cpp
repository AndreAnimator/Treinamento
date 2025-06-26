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
    // Divide and conquer solution
    TreeNode* toBST(vector<int> const &nums, int low, int high)
    {
        // Missed this if:
        if(low > high) 
            return NULL;
        
        /** Dont need this IF
        
        // if the array contains only one element
    
        if (low == high)                    // common comparison
        {
            TreeNode *node = new TreeNode();
            node->val = nums[low];
            return node;
        }
        **/
    
        /** Dont need this IF

        // if the array contains only two elements

        if (high - low == 1)                // common comparison
        {
            TreeNode *node = new TreeNode();
            node->val = nums[low];
            TreeNode *right_node = new TreeNode();
            right_node->val = nums[high];
            node->right = right_node;
            return node;
        } **/
    
        // find the middle element
        // old int mid = (low + high) / 2;
        int mid = low + (high - low)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        // recur for the left subarray
        node->left = toBST(nums, low, mid - 1);
    
        // recur for the right subarray
        node->right = toBST(nums, mid + 1, high);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums, 0, nums.size()-1);
    }
};

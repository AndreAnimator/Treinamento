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
        vector<int> saida;
        if(!root){
            return {};
        }
        queue<TreeNode*> atual;
        atual.push(root);
        while(!atual.empty()){
            int tamanho = atual.size();
            for(int i = 0; i < tamanho; i++){
                TreeNode* temp = atual.front();
                atual.pop();
                if(temp->left){
                    atual.push(temp->left);
                }
                if(temp->right){
                    atual.push(temp->right);
                }
                if(i == tamanho - 1){
                    saida.push_back(temp->val);
                }
            }
        }

        return saida;
    }
};

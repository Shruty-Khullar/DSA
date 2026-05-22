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
        if(root==nullptr)
            return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long max_width = 1;
        while(!q.empty()){
            int size = q.size();
            long long topIndex = q.front().second, li=0, fi=0;
            for(int i=0;i<size;i++){
                TreeNode* top = q.front().first;
                long long index = q.front().second - topIndex;
                q.pop();
                if(i==0){
                    fi=index;
                }
                if(i==size-1){
                    li=index;
                }
                if(top->left)
                    q.push({top->left, 2*index+1});
                if(top->right)
                    q.push({top->right, 2*index + 2});
            }
            max_width = max(max_width, li-fi+1);
        }
        return max_width;
    }
};
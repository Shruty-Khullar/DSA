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
public:
    void makeParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent){
        if(root==nullptr)
            return;
        if(root->left)
            parent[root->left] = root;
        if(root->right)
            parent[root->right]=root;
        makeParent(root->left, parent);
        makeParent(root->right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        makeParent(root, parent);
        set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target,0});
        visited.insert(target);
        vector<int> temp;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* top = q.front().first;
                int level = q.front().second;
                q.pop();
                if(level==k)
                    temp.push_back(top->val);
                if(top->left && visited.find(top->left)==visited.end()){
                    q.push({top->left, level+1});
                    visited.insert(top->left);
                } 
                if(top->right && visited.find(top->right)==visited.end()){
                    q.push({top->right, level+1});
                    visited.insert(top->right);
                }
                if(parent[top]!=nullptr && visited.find(parent[top])==visited.end()){
                    q.push({parent[top], level+1});
                    visited.insert(parent[top]);
                }
            }
            if(temp.size()!=0)
                break;
        }
        return temp;
        
    }
};
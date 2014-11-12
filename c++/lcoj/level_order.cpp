/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    typedef pair<int, TreeNode*> pi;
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<pi> q;
        q.push(pi(0, root));
        vector<int> temp;
        vector< vector<int> > res;
        if(!root) {
            return res;
        }
        int prev = 0;
        while(!q.empty()) {
            pi curr = q.front();
            q.pop();
            if(curr.second->left)
                q.push(pi(curr.first + 1, curr.second->left));
            if(curr.second->right)
                q.push(pi(curr.first + 1, curr.second->right));
            if(curr.first > prev) { //new level started
                res.push_back(vector<int>(temp));
                temp.clear();
                prev = curr.first;
            }
            temp.push_back(curr.second->val);
        }
        if(temp.size() > 0) {
            res.push_back(temp);
        }
        return res;
    }
};

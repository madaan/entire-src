//sg
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for binary tree
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        //get min in left, max in right and recur
        if(root == NULL) {
            return true;
        }
        bool l_ok, r_ok;
        if(root -> right) {
            TreeNode *tmp = root -> right;
            while(tmp -> left) {
                tmp = tmp -> left;
            }
            int rval = tmp -> val;
            r_ok = (root -> val < rval);
        } else {
            r_ok = true;
        }
        if(root -> left) {
            TreeNode *tmp = root -> left;
            while(tmp -> right) {
                tmp = tmp -> right;
            }
            int lval = tmp -> val;
            l_ok = root -> val > lval;
        } else {
            l_ok = true;
        }

        if(l_ok && r_ok) {
            return isValidBST(root->left) && isValidBST(root->right);
        } else {
            return false;
        }
    }
};

int main() {
    TreeNode t(4);
    Solution s;
    cout << s.isValidBST(&t) << "\n";
    return 0;
}

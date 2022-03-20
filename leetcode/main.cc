#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        if (root == nullptr){
            return nullptr;
        }
        TreeNode* maxLeft = nullptr;
        TreeNode* maxRight = nullptr;
        if (root->left == nullptr && root->right == nullptr)
        {
            return root;
        }
        if (root->left == nullptr) {
            maxRight =  maxNode(root->right);
            return root->val >= maxRight->val?root:maxRight;
        }
        if (root->right == nullptr) {
            maxLeft = maxNode(root->left);
            return root->val >= maxLeft->val?root:maxLeft;
        }
        maxLeft = maxNode(root->left);
        maxRight = maxNode(root->right);
        TreeNode* maxSun = maxLeft->val >= maxRight->val?maxLeft:maxRight;
        return root->val >= maxSun->val?root:maxSun;
    }
};

int main()
{
    Solution s;
    vector<int> v {3,2,1,4,5};
    s.maxNode(NULL);
    return 0;
}

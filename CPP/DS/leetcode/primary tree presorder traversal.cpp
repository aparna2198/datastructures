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
    vector<int> preorderTraversal(TreeNode* root) {
     vector<int> result(3);// i have to mention the size else ill get the runtime binding error runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h)
        int i =0;
        stack<TreeNode*> s;
        if(root==NULL)
        return  result;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* node=s.top();
            result[i++]=node->val;
            s.pop();
            if(node->right!=NULL)
            s.push(node->right);
            if(node->left!=NULL)
            s.push(node->left);
        }
    return result;
    }
};

/*
iterative method instead of recursion
first i created a variable of vector type having int type of elements
taken a stack varible


algorthm works on 
first  takes in root value in stack
fillls thje stack with the all the left nodes on the root now once the last leaf node ka left is null it comes of that while loop
next  stack elements are popped and now each elememt bein popped it it checked forthat wheather it has  a right node or not 
*/

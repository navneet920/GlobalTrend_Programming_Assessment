#include<iostream>
#include<algorithm>
#include<cLimits>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class solution{
    public:
    int maxPthSum(TreeNode* root){
        int maxSum = INT_MIN;
        maxPthSumHelper(root,maxSum);
        return maxSum;
    }
    private:
    int maxPthSumHelper(TreeNode* node,int& maxSum){
        if(!node) return 0;

        int leftSum =max(0,maxPthSumHelper(node->left,maxSum));
        int rightSum = max(0,maxPthSumHelper(node->right,maxSum));
        int currentPathSum = node->val + leftSum+ rightSum;
        maxSum = max(maxSum,currentPathSum);
        return node->val+max(leftSum,rightSum);
    }
};
int main(){
    TreeNode* root= new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    solution sol;
    cout<<"The maximun path sum is : "<<sol.maxPthSum(root)<<endl;
    return 0;
}
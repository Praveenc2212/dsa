class Solution {
public:
vector<int> arr;
void fun(TreeNode * root ){

    if( root == nullptr) return 0;
    int left = 0;
    int right = 0 ;
    if( root->left != nullptr && root->right != nullptr){
        left = root->left->val;
        right = root->right->val;
    }

    fun( root->left);
    fun( root->right);

    return ;
}

    int findTilt(TreeNode* root) {  
        fun(root);
        return *max_element(arr.begin() , arr.end() );      
    }
};
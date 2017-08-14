Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

************************************************************************************************************

bool findPath(TreeNode *root, vector<int> &path, int k)
{
    if (root == NULL) return false;
 
    path.push_back(root->val);
 
    if (root->val == k)
        return true;
 
         if( (findPath(root->left, path, k)) ||
         (findPath(root->right, path, k)) )
        return true;
 
    path.pop_back();
    return false;
}
 
int Solution::lca(TreeNode* root, int n1, int n2) {
     vector<int> path1, path2;
 
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
          return -1;
 
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

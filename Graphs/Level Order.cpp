Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.

*********************************************************************************************************************************

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<pair<TreeNode*,int>> Q;
    Q.push(make_pair(A,0));
    vector<int> r;
    vector<vector<int>> res;
    int k = 0;
    while(!Q.empty()){
        pair<TreeNode*,int> fr = Q.front();
        int l = fr.second;
        if(l > k){
            res.push_back(r);
            r.clear();
            k = l;
        }
        r.push_back(fr.first->val);
        Q.pop();
        if(fr.first->left){Q.push(make_pair((fr.first->left),l+1)); }
        if(fr.first->right){Q.push(make_pair((fr.first->right),l+1)); }
    }
    if(r.size() != 0 )res.push_back(r);
    return res;
}

Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes 
- Your solution should run in linear time and not take memory more than O(height of T).
- Assume all values in BST are distinct.

Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

***********************************************************************************************************************************************

bool check(TreeNode* A, int B, unordered_map<int , bool>& map){
    if(A == NULL) return false;
    if(!map.empty() && map.find(B-(A->val)) != map.end()) return true;
    if(map.empty() || map.find(A->val) == map.end())map[A->val] = true;
    return (check(A->left , B , map) || check(A->right , B  , map));
}
 
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_map<int , bool> S;
    return check(A , B , S);
}

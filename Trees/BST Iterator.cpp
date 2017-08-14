Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 

**************************************************************************************************************

stack<TreeNode *> myStack;

void pushAll(TreeNode *node) {
        while (node != NULL) {
            myStack.push(node);
            node = node->left;
        }
    }

BSTIterator::BSTIterator(TreeNode *root) {
    pushAll(root);
}

bool BSTIterator::hasNext() {
     return !myStack.empty();
}

int BSTIterator::next() {
    TreeNode *tmpNode = myStack.top();
    myStack.pop();
    pushAll(tmpNode->right);
    return tmpNode->val;
}


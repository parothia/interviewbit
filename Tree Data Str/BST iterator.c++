//  Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
// 
// The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.
 
void pushAll(TreeNode *root,stack<TreeNode*> &s) {
    if(!root) return ;
    while(root) {
        s.push(root);
        root=root->left;
    }
}
stack<TreeNode *> s;
BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty()) {
        s.pop();
    }
    pushAll(root,s);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (s.empty())?false:true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* t=s.top();
    s.pop();
    pushAll(t->right,s);
    return t->val;

}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

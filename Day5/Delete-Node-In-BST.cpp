/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    

      if (root == NULL) {
        return NULL;
    }

    if (key < root -> data) {
        root -> left = deleteNode(root -> left, key);
    }

    else if (key > root -> data) {
        root -> right = deleteNode(root -> right, key);
    }

    else {
        if (root -> left == NULL && root -> right == NULL) {
            return NULL;
        }

        if (root -> left == NULL) {
            // Node doesn't have a left subtree.
            return root -> right;
        }

        if (root -> right == NULL) {
            // Node doesn't have a right subtree.
            return root -> left;
        }


        // Find the minimum value in the right Subtree(successor).
        BinaryTreeNode<int>* rightSubtree = root -> right;

        while (rightSubtree -> left != NULL) {
            rightSubtree = rightSubtree -> left;
        }

        root -> data = rightSubtree -> data;

        // Delete the inorder successor.
        root -> right = deleteNode(root -> right, rightSubtree -> data);
    }

    return root;
}

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTreeHelper(TreeNode<int> *currentNode, TreeNode<int> *lastNode)
{
    if (currentNode == NULL)
    {
        return lastNode;
    }

    if (lastNode != NULL)
    {
        lastNode->right = currentNode;
    }
    TreeNode<int> *left = currentNode->left;
    TreeNode<int> *right = currentNode->right;
    currentNode->left = currentNode->right = NULL;

    TreeNode<int> *newLastNode = flattenBinaryTreeHelper(left, currentNode);

    newLastNode = flattenBinaryTreeHelper(right, newLastNode);

    return newLastNode;
}

void flattenBinaryTree(TreeNode<int> *root)
{
    flattenBinaryTreeHelper(root, NULL);
}

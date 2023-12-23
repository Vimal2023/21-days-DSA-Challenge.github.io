/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/

void inorder(BinaryTreeNode *root, vector<int> &nums)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, nums);

    nums.push_back(root->data);

    inorder(root->right, nums);
}

bool pairSumBst(BinaryTreeNode *root, int k)
{
    // Vector to store the inorder traversal of the BST.
    vector<int> nums;

    inorder(root, nums);

    // Iterating over the nums list using 2 - pointer.
    int i = 0, j = nums.size() - 1;

    // Iterate till 'i' is less than 'j'.
    while (i < j)
    {
        if (nums[i] + nums[j] == k)
        {
            return true;
        }

        // If the sum of elements at index 'i' and 'j' is less than target 'k'.
        if (nums[i] + nums[j] < k)
        {

            // Increment the left pointer 'i'.
            i = i + 1;
        }

        // If the sum of elements at index 'i' and 'j' is greater than target 'k'.
        else
        {

            // Decrement the right pointer 'j'.
            j = j - 1;
        }
    }

    return false;
}

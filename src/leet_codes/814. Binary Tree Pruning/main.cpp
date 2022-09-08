#include <iostream>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFS(TreeNode *&current, TreeNode *root)
{
    if (current == nullptr)
        return -1;

    int left = DFS(current->left, root);   // 0
    int right = DFS(current->right, root); //

    cout << "Left: " << left << endl;
    cout << "Right: " << right << endl;

    if (left == -1 && right == -1 && current->val == 0){
        cout << "Deleting current: " << current->val << endl;
        current = nullptr;
    }

    if (current != nullptr)
        return current->val;
    else
        return -1;
}

void print(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Pre order
    print(root->left);
    print(root->right);

    cout << root->val << " ";
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *ptr_root = root;
    TreeNode *temp1 = new TreeNode(0);
    TreeNode *temp2 = new TreeNode(0);
    TreeNode *temp3 = new TreeNode(1);

    root->left = nullptr;
    root->right = temp1;
    temp1->left = temp2;
    temp1->right = temp3;


    DFS(root, ptr_root);
    print(root);

    return 0;
}
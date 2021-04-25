/* ------------------------------------------------------------------|
给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

 

示例 1：


输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
示例 2：


输入：root = [5,1,7]
输出：[1,null,5,null,7]
 

提示：

树中节点数的取值范围是 [1, 100]
0 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-order-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//TreeNode* resroot = nullptr;
//void dfs(TreeNode* root) {
//    if (root == nullptr) {
//        return;
//    }
//
//    dfs(root->left);
//
//    resroot->right = root;
//    root->left = nullptr;
//    resroot = root;
//
//    dfs(root->right);
//}
//TreeNode* increasingBST(TreeNode* root) {
//    TreeNode* dummy = new TreeNode(-1);
//    resroot = dummy;
//    dfs(root);
//    return dummy->right;
//}

TreeNode* dummy = new TreeNode(-1);
TreeNode* resroot = nullptr;
void dfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    dfs(root->left);

    if (resroot == nullptr) {
        resroot = root;
        dummy->right = resroot;
    }
    else {
        root->left = nullptr;
        resroot->right = root;
        resroot = root;
    }

    dfs(root->right);
}
TreeNode* increasingBST(TreeNode* root) {
    dfs(root);
    return dummy->right;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(6);

    increasingBST(root);
}
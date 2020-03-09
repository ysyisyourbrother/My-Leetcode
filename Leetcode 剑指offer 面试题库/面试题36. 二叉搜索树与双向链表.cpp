#include "headfile.h"
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* pre; // 标记上一个节点
    Node* first; // 标记第一个节点
    Solution():pre(NULL){}

    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        helper(root);
        first->left = pre;
        pre->right = first;
        return first;
    }
    void helper(Node* root)
    {
        if(root == NULL)
            return;
        if(pre == NULL && root->left == NULL)
            first = root;
            
        // 中序遍历，每次遍历到一个点就和pre连接起来
        helper(root->left);
        root->left = pre; // 左指针指向前驱
        if(pre != NULL)
            pre->right = root; //pre的右指针指向后继
        pre = root; // 更新上一个节点
        helper(root->right);
    }
};
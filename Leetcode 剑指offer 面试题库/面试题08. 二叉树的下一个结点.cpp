# include "headfile.h"
using namespace std;
//牛客网：https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking&from=cyc_github

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return NULL;
        // 如果当前结点没有右结点，则要向上找 第一个左子树包含当前结点的结点
        if(pNode->right == NULL)
        {
            while(pNode->next!=NULL)
            {
                TreeLinkNode* par = pNode->next;
                if(par->left == pNode)
                    return par;
                pNode = par;
            }
            return NULL;
        }
        //  如果存在右结点，一直找到右结点的最左结点
        TreeLinkNode* cur = pNode->right;
        while(cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }
};
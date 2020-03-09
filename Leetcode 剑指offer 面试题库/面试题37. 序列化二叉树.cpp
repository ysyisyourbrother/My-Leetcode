#include "headfile.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "[]";
        string res = "[";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();
            // 如果当前节点是空的话，直接继续循环
            if(cur == NULL) 
            {
                res+="null,";
                continue;   
            }
            // 如果不是空的，将当前节点加入res，并将孩子加入队列
            res=res+to_string(cur->val)+",";
            que.push(cur->left);
            que.push(cur->right);
        }
        res = trimNULL(res); // 去掉后面所有的null,
        res[res.size()-1] = ']';
        return res; // 最后一个逗号用中括号代替
    }

    string trimNULL(string data)
    {
        // 将最后的所有null,去掉
        int i;
        for(i = data.size()-5;i>=0;i-=5)
        {
            if(data.substr(i,5)!="null,")
                break;
        }
        data = data.substr(0,i+5);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string> target = tran(data);
        if(target.size()==0) return NULL;
        TreeNode* root = new TreeNode(stoi(target[0])); // 构造根节点
        queue<TreeNode*> que;
        que.push(root);
        // 如果不是空的，迭代开始建树
        helper(target,1 , que);
        return root;
    }
    vector<string> tran(string data)
    {
        // 先将data解析成一个vector<string>数组
        vector<string> target;
        int i =1;
        while(data[i]!=']')
        {
            if(data[i]==',')
                i++;
            string tmp;
            while(data[i]!=',' && data[i]!=']')
            {
                tmp+=data[i];
                i++;
            }
            target.push_back(tmp);
        }
        return target;
    }

    void helper(vector<string> target, int begin, queue<TreeNode*> que) // begin 是开始的字符  layer是当前建到第几层树了
    {
        queue<TreeNode*> que_next;// 构造下一层的队列
        while(!que.empty()) // que 是上一层的节点的队列
        {
            TreeNode* cur = que.front();
            que.pop();
            // 构造当前节点的字节点 同时加入queue中
            if(cur != NULL)
            {
                if(begin<target.size()) // 先构造当前节点的左边节点
                {
                    if(target[begin]!="null")
                    {
                        cur->left = new TreeNode(stoi(target[begin]));
                        que_next.push(cur->left);
                    }
                    begin++;
                }
                if(begin<target.size()) // 再构造当前节点的右边节点
                {
                    if(target[begin]!="null") // 为空的话就不构造节点
                    {
                        cur->right = new TreeNode(stoi(target[begin]));
                        que_next.push(cur->right);
                    }
                    begin++;
                }
            }
        }
        if(begin<target.size())
            helper(target, begin, que_next);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main()
{
    string a ="123";
    a[2] = '2';
    cout<<a;
}
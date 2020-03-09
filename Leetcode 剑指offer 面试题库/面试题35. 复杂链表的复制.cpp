#include "headfile.h"
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map<Node*, int> mymap1; // 记录原来链表中，指针和index的关系
    unordered_map<int, Node*> mymap2; // 记录复制链表中，index和指针的关系
    Node* copyRandomList(Node* head) {
        Node* res = new Node(0);// 拷贝的链表
        Node* copy_cur = res; // 拷贝链表当前位置
        Node* cur = head; // 原链表当前位置
        int count = 0;
        while(cur!=NULL)
        {
            copy_cur->next = new Node(cur->val);
            copy_cur = copy_cur->next;
            mymap1[cur] = count; // 记录原来链表中，指针和index的关系
            mymap2[count] = copy_cur; // 记录复制链表中，index和指针的关系
            cur=cur->next;
            count++;
        }
        // 记录null的位置
        mymap1[NULL] = count; 
        mymap2[count] = NULL;

        // 开始复制ramdon指针
        cur = head;
        copy_cur = res->next;
        count = 0;
        while(cur!=NULL)
        {
            // 先用randomptr查到对应的index
            int index = mymap1[cur->random];
            // 用index找复制链表中的指针
            Node* ptr = mymap2[index];
            copy_cur->random = ptr;

            //向后移动指针
            cur= cur->next;
            copy_cur = copy_cur->next;
        }
        return res->next;
    }

    // 也可以使用深度优先搜索，模仿图的遍历
    Node* dfs(Node* head, unordered_map<Node*, Node*>& used) {
        if (!head) return nullptr;
        if (used.count(head)) return used[head];
        Node *res = new Node(head->val);
        used[head] = res;
        res->next = dfs(head->next, used);
        res->random = dfs(head->random, used);    
        return res;
    }
};
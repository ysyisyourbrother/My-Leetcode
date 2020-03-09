# include "headfile.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    //方法1 递归
     vector<int> reversePrint(ListNode* head) {
         vector<int>res;
         helper(head,res);
         return res;
     }
     void helper(ListNode* head,vector<int>& res){
         if(head){
             if(head->next){
                  helper(head->next,res);
             }
             res.push_back(head->val);
         }
         return ;
     }
    
    //方法2 使用栈
    vector<int> reversePrint2(ListNode* head) {
         vector<int>res;
         stack<int>sk;
         while(head){
             sk.push(head->val);
             head=head->next;
         }
         while(!sk.empty()){
             res.push_back(sk.top());
             sk.pop();
         }
         return res;
    
    }
};
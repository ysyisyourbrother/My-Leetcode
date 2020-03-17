#include "headfile.h"
using namespace std;
//数组最后一个值为 根节点值，进行遍历当值大于根节点时break，说明左子树遍历完毕。第二次循环判断右子树，若其中有值小于根节点值则证明不是后序遍历。 
//左右节点往下利用递归实现
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return judge(postorder,0,postorder.size()-1);
    }

    bool judge(vector<int>&vec,int left,int right){
        if(left>=right){
            return true;
        }
        int root=vec[right];
        int i=left;
        for(;i<right;i++){ // 找到第一个大于root的，前面为左子树
            if(vec[i]>root){
                break;
            }
        }
        int j=i;
        for(;j<right;j++){ // 右子树如有值小于根节点值则证明不是后序遍历
            if(vec[j]<root){
                return false;
            }
        }
        return judge(vec,left,i-1) && judge(vec,i,right-1);
    }
};

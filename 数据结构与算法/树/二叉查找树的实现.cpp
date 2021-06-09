#include <iostream>
#include <stack>

using namespace std;

// Functioanl stype insertion and deletion in BST

typedef int T;
struct BinaryNode{
  T data;
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};
};

//release all nodes in root
void clear(BinaryNode *root){
  if (root){
    clear(root->left);
    clear(root->right);
    delete root;
  }
}
//inorder traversal
void inorder (BinaryNode *root, void (*visit)(T &e)){
   if (root!=NULL){
    inorder(root->left, visit);
    (*visit)(root -> data);
    inorder(root->right, visit);
   };
}
//preorder traversal
void preorder (BinaryNode *root, void (*visit)(T &e)){
   if (root!=NULL){
     (*visit)(root -> data);
     preorder(root->left, visit);
     preorder(root->right, visit);
   };
}
//returns the pointer which points to node with key=x
BinaryNode* search(BinaryNode* root, T x){
  if (root==NULL)
     return NULL;
  if (x==root->data)
    return root;
  else if (x < root->data)
    return search(root->left,x);
  else
    return search(root->right,x);
}

bool isLeaf(BinaryNode* t){
  return ((t->left==NULL) && (t->right==NULL));
}
//removes node pointed by t in BST and returns the new BST. functional style 
BinaryNode* remove_node_fs(BinaryNode* t);

//returns the BST where x  is removed. Functional style.
BinaryNode* remove_fs(BinaryNode* root, T x){
  if (root==NULL)
    return NULL;
  if (root->data < x){
    root->right = remove_fs(root->right,x);//recurse and hang the new right subtree to root's right.
    return root;  
  }else if (root->data > x){
    root->left = remove_fs(root->left,x); //recurse and hang the new left subtree to root's left.
    return root;
  }else 
  return remove_node_fs(root); //removes the root node and returns the new BST
}
//return the new BST where root is removed.
BinaryNode* remove_node_fs(BinaryNode* root){
    BinaryNode * newroot;
    if (isLeaf(root)){ //the BST has only one root node.
        delete root;
        return NULL; // result is empty BST.
    } 
    else if (root->left == NULL) {
       newroot = root->right; //root's left subtree is empty, the right subtree is the new BST.
       delete root; 
       return newroot;
    } else if (root->right==NULL){
       newroot = root->left; //the right subtree is empty and the left substree is the new BST.
       delete root;
       return newroot;
   }else {//root has both nonempty subtrees
      BinaryNode* parent = root;
      newroot = root->right;
      //find the successor of root->data on root's right subtree
      while (newroot->left != NULL){
         parent = newroot;
         newroot = newroot->left;
      }
      root->data = newroot->data;//replace root->data by its successor key
      if (parent==root) //root's right child has no left child.
         root->right = remove_node_fs(newroot); //remove newroot and hang the result BST to the right of root. 
      else
         parent->left = remove_node_fs(newroot);//hang the new BST after removing to parent's left, as it is the left subtree of parent.
     return root;
  }
}

void print(int &x){
  cout << x << "  ";
}

void inorder_nonrecursive(BinaryNode *root, void (*visit)(T &e)){
  stack<BinaryNode*> s;
  while (root || !s.empty()){
   if (root){
      s.push(root);
      root = root -> left;
   }
   else {
     BinaryNode * p = s.top();
     visit(p -> data);
     s.pop();
     root = p -> right;
   }
  }  
}
//insert x into root and returns the new BST
BinaryNode* insert_fs(BinaryNode* root, const T &x){
    if (root==NULL)
      return new BinaryNode(x);
    else if (x<root->data)
      root->left = insert_fs(root->left,x);
    else 
      root->right = insert_fs(root->right,x);
    return root;
}


int main(int argc, char* argv[]){
  BinaryNode *root = NULL;
  int A[] = {12,3,5,1,6,20};
  for (int i=0; i<6;i++)
    root = insert_fs(root, A[i]);
  cout <<"Preorder:";
  preorder(root, print);
  cout<<endl;
  cout <<"Inorder: ";
  inorder(root, print);
  cout<<endl;
  int k;
  cout<<"input some key to remove:";
  cin >> k;
  cout<<"remove:" <<k <<endl;
  root = remove_fs(root, k);  
  cout <<"After removing \nPreorder:";
  preorder(root, print);
  cout<<endl;
  cout <<"Inorder: ";
  inorder(root, print);
  cout<<endl;
  clear(root);
  return 0;

}

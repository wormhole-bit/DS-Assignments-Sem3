#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node* left;
node* right;
node(int x){
    data = x;
    left = nullptr;
    right = nullptr;
}
~node(){
        delete left;
        delete right;    
}
};
node *insert(node *root,int val){
    if(root == nullptr){
     root = new node(val);
    }
    if(val<root->data) {
        root->left = insert(root->left,val);
    }
    if(val>root->data){
        root->right = insert(root->right,val);
    }
    return root;
}


void inorder(node *root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
     if(root == nullptr) return;
     cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
bool isBSTUtil(node* root, int minVal, int maxVal) {
    if (root == nullptr) return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}
bool checkBinary(node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
int minDepth(node* root) {
    if (root == nullptr) return 0;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}
int maxDepth(node* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


void postorder(node *root){
 if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void findPreSuc(node* root, int key) {
    node* pre = nullptr;
   node* suc = nullptr;

    while (root) {
        if (root->data == key) {
                if (root->left) {
                node* temp = root->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }
            if (root->right) {
                node* temp = root->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
            break;
        }
        else if (key < root->data) {
            suc = root; 
            root = root->left;
        } 
        else {
            pre = root;  
            root = root->right;
        }
    }
    cout << "Predecessor: ";
    if (pre) cout << pre->data << endl;
    else cout << "None" << endl;
    cout << "Successor: ";
    if (suc) cout << suc->data << endl;
    else cout << "None" << endl;
}

bool search(node *root,int val){
if(root == nullptr) return false;
if(root->data == val) return true;
else if(root->data>val){
    return search(root->left,val);
}
else return search(root->right,val);
}
void minimum(node *root){
    if(root == nullptr) cout<<"empty tree";
    else{
        node *temp = root;
        while(temp->left!=nullptr){
            temp = temp->left;
        }
        cout<<"min element is : "<<temp->data<<endl;
    }
}
void maximum(node *root){
    if(root == nullptr) cout<<"empty tree";
    else{
        node *temp = root;
        while(temp->right!=nullptr){
            temp = temp->right;
        }
        cout<<"max element is : "<<temp->data<<endl;
    }
}


int main(){
    node *root = nullptr;
    root = insert(root,8);
     insert(root,12);
      insert(root,6);
       insert(root,45);
         insert(root,53);
        insert(root,7);
         insert(root,4);
          insert(root,18);
            insert(root,5);
          inorder(root);
          cout<<endl;
         // minimum(root);
         // maximum(root);
         // search(root,18)?cout<<"found"<<endl:cout<<"error not found"<<endl;
        //  search(root,1)?cout<<"found"<<endl:cout<<"error not found"<<endl;
        findPreSuc(root,7);

    return 0;
}
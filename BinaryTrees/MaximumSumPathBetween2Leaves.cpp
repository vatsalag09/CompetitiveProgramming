
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include<bits/stdc++.h>
long long int ans = 0;
long long int dfs(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }   
    
    long long int l = 0, r = 0;
    
    if(root->left != NULL){
        l = dfs(root->left);
    }
    
    if(root->right != NULL){
        r = dfs(root->right);
    }
    
    if(root->left != NULL && root->right != NULL){
        ans = max(ans, l + r + root->data);
    }
    
    return max(l, r) + root->data;
}


long long int maximumSumLeafpath(BinaryTreeNode<int> *root){
    dfs(root);
    
    return ans;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << maximumSumLeafpath(root) << endl;
}



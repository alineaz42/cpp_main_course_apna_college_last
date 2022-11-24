#include"bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void getHorizontalDistance(Node* root,int hdis,map<int,vector<int>> &m){
    if(root==NULL){
        return;
    }
    m[hdis].push_back(root->data);
    getHorizontalDistance(root->left,hdis-1,m);
    getHorizontalDistance(root->right,hdis+1,m);
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);
    map<int,vector<int>> m;
    int hdis = 0; // horizontal distance currently 0
    getHorizontalDistance(root,hdis,m);
    //* itrator of the map to print the value of the getHorizontalDistance
    map<int,vector<int>> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        for(int i=0;i<(it->second).size();i++){
            cout<<(it->second)[i]<<" ";
        }cout<<endl;
    }
    return 0;
}
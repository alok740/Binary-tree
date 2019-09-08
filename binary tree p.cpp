// C++ program to illustrate the 
// iterators in vector 
#include <iostream> 
#include <vector> 
#include <bits/stdc++.h>
using namespace std; 
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node* root=NULL;
queue<struct node*> q;

void insert(int x)
{
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=x;
    temp1->left=NULL;
    temp1->right=NULL;
    if(root==NULL)
    {
        root=temp1;
        q.push(root);
    }
    else
    {
        struct node* ptr = q.front();
 
        if(ptr->left==NULL)
        {
            ptr->left=temp1;
            q.push(ptr->left);
        }
        else if(ptr->right==NULL)
        {
            ptr->right=temp1;
            q.push(ptr->right);
        }
      if(ptr->left!=NULL && ptr->right!=NULL)
        q.pop();
        
        
    }
    
}

void print(struct node* ptr)
{
    queue<struct node* > que;
    que.push(ptr);
    
    while(que.size()!=0)
    {
     struct node* am=que.front();
     cout<<am->data<<endl;
     que.pop();
     if(am->left!=NULL)
     {
         que.push(am->left);
         
    
     }
     if(am->right!=NULL)
     {
         que.push(am->right);
 
     }
        
    }
}
int main() 
{ 
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insert(x);
    }
    struct node* val=root;
    cout<<val->data;
    cout<<val->left->data;
    cout<<val->right->data;
    cout<<val->left->left->data;
    cout<<val->left->right->data<<endl;
    print(root);
    
    
	return 0; 
} 

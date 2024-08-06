//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int findPosition(int in[],int element,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(in[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node *solve(int n,int in[],int post[],int inorderStart,int inorderEnd,int &index)
    {
        if(index<0||inorderStart>inorderEnd)return NULL;
        
        int element=post[index--];
        Node *root=new Node(element);
        int position=findPosition(in,element,inorderStart,inorderEnd);
        
        root->right=solve(n,in,post,position+1,inorderEnd,index);
        root->left=solve(n,in,post,inorderStart,position-1,index);
        
        return root;
        
    }
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        int index=n-1;
        Node *ans=solve(n,in,post,0,n-1,index);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
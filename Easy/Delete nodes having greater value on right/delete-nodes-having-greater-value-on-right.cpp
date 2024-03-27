//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverse(Node *head)
    {
        // ************************************Recusion reverse O(n) TC,SC***********************
        // if(head==NULL||head->next==NULL)
        // {
        //     return head;
        // }
        // else
        // {
        //     Node *smallHead=reverse(head->next);
        //     head->next->next=head;
        //     head->next=NULL;
        //     return smallHead;
        // }
        // ************************************ reverse O(n) TC,O(1)SC***********************
        Node *prev=NULL;
        Node *next=NULL;
        Node *cur=head;
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
       head=reverse(head);
       Node *temp=head;
       
       while(temp->next)
       {
           if(temp->data>temp->next->data)
           {
               temp->next=temp->next->next;
           }
           else
           {
               temp=temp->next;
           }
       }
       Node *ans=reverse(head);
       return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends
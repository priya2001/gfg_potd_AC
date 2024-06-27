//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    public:
    stack<int>s1;
    stack<int>s2;
    
    
    twoStacks()
    {
        
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        s1.push(x);
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       s2.push(x);
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(!s1.empty())
        {
            int top1=s1.top();
            s1.pop();
            return top1;
        }
        else 
        {
            return -1;
        }
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(!s2.empty())
        {
            int top2=s2.top();
            s2.pop();
            return top2;
        }
        else 
        {
            return -1;
        }
    }
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends
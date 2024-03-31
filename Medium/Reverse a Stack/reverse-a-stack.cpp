//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*
Approach-1 (Using O(n) Auxiliary Space (we took extra one temp stack))
Simply write a story like recursion and trust it
Time : O(n^2)
Space : O(n) Auxiliary Space (we took extra one temp stack)
*/
class Solution{
public:
    void Reverse(stack<int> &St){
        
        if(St.empty())return ;
        
        int top=St.top();
        St.pop();
        Reverse(St); //I am hoping my Reverse function will reverse the remaining stack
        
        
        //Now I need to push top at the bottom of the stack
        stack<int>temp;
        while(!St.empty())
        {
            temp.push(St.top());
            St.pop();
        }
        
        St.push(top); //push at bottom
        while(!temp.empty())  //Now push remaining elements
        {
            St.push(temp.top());
            temp.pop();
        }
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
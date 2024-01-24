//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
           unordered_map<string, int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        
        int max_val=0;
        for(auto it: mpp){
            if(max_val<it.second){
                max_val=it.second;
            }
        }
        
        string str="";
        for(auto it: mpp){
            if(it.second==max_val){
                
                
                if(str.empty()){
                   str=it.first; 
                }
                
                else{
                    if(str> it.first){
                        str=it.first;
                    }
                }
            }
        }
        
        
        return {str, to_string(max_val)}; 
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
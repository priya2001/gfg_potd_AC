//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
              int sum = 0 ;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '-' && i == 0) 
            continue ;
            else if(s[i] == '0')
                sum = sum*10 + 0 ;
            else if(s[i] == '1')
                sum = sum*10 + 1 ;
            else if(s[i] == '2')
                sum = sum*10 + 2 ;
            else if(s[i] == '3')
                sum = sum*10 + 3 ;   
            else if(s[i] == '4')
                sum = sum*10 + 4 ;    
            else if(s[i] == '5')
                sum = sum*10 + 5 ;  
            else if(s[i] == '6')
                sum = sum*10 + 6 ;
            else if(s[i] == '7')
                sum = sum*10 + 7 ;
            else if(s[i] == '8')
                sum = sum*10 + 8 ;
            else if(s[i] == '9')
                sum = sum*10 + 9 ;
            else 
                return -1 ;
        }
        if(s[0] == '-')
          return -sum ;
        return sum ;  
    
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
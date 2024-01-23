//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:
    string stringFilter(string str) 
    { 
        //code here.
        int i=0;
        while(i<str.size())
        {
            if(str[i]=='b')
            {
                str.erase(i,1);
            }
            else if(str[i]=='a'&&str[i+1]=='c')
            {
                str.erase(i,2);
            }
            else 
            {
                i++;
            }
        }
        return str;
    } 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;
   		
   		Solution ob;
   		cout <<ob.stringFilter(s) << "\n";

   		
   	}

    return 0;
}
// } Driver Code Ends
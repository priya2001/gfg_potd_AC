//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        map<char,int>mp;
        int maxi=0;
        char maxchar='A';
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
        }
        for(auto j:mp)
        {
            int fre=j.second;
            if(fre>maxi)
            {
                maxi=fre;
                if(j.first>maxchar)
                {
                    maxchar=j.first;
                }
            }
        }
        return maxchar;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends
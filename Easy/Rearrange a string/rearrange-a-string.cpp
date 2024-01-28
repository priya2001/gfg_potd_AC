//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        string str1="";
        int sum=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                sum=sum+(str[i]-'0');     //sum=sum+int(str[i]);
            }
            else if(str[i]>='A'&&str[i]<='Z')
            {
                str1=str1+str[i];
            }
        }
        sort(str1.begin(),str1.end());  // sort str1
        if(sum>0)
        {
            return str1+to_string(sum);
        }
        else
        {
            return str1;
        }
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}


// } Driver Code Ends
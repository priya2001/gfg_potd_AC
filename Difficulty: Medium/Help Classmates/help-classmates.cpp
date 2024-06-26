//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // vector<int>res(n,-1);
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(arr[i]>arr[j])
        //         {
        //             res[i]=arr[j];
        //             break;
        //         }
        //     }
        // }
        // return res;
        
        stack<int>s;
        vector<int>v;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                v.push_back(-1);
            }
            else if(s.size()>0&&s.top()<arr[i])
            {
                v.push_back(s.top());
            }
            else if(s.size()>0&&s.top()>=arr[i])
            {
                while(s.size()>0&&s.top()>=arr[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    v.push_back(-1);
                }
                else 
                {
                    v.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        
        reverse(v.begin(),v.end());
        return v;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends
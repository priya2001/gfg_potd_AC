//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

string printNumber(string , int);

// User function pasted here
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,temp;
		cin>>s;
		int i,len=s.length();
		
		cout << printNumber(s,len) << "\n";
	}
	return 0;
}
// } Driver Code Ends


//User function template for C++
char getDecimalKey(char ch)
{
    if(ch=='a'||ch=='b'||ch=='c')
        {
            return '2';
        }
        else if(ch=='d'||ch=='e'||ch=='f')
        {
            return '3';
        }
        else if(ch=='g'||ch=='h'||ch=='i')
        {
            return '4';
        }
        else if(ch=='j'||ch=='k'||ch=='l')
        {
            return '5';
        }
        else if(ch=='m'||ch=='n'||ch=='o')
        {
            return '6';
        }
        else if(ch=='p'||ch=='q'||ch=='r'||ch=='s')
        {
            return '7';
        }
        else if(ch=='t'||ch=='u'||ch=='v')
        {
            return '8';
        }
        else if(ch=='w'||ch=='x'||ch=='y'||ch=='z')
        {
            return '9';
        }
        else
        {
            return '1';
        }
}

//Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n) 
{
    //code here
    for(int i=0;i<n;i++)
    {
        s[i]=getDecimalKey(s[i]);
    }
    return s;
}

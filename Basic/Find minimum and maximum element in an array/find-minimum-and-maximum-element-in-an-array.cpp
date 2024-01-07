//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends


pair<long long, long long> getMinMax(long long a[], int n) {
    
    long long maxi=a[0]; //maxi is used to store maximum value
    long long mini=a[0]; //mini is used to store minimum value
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,a[i]); //largest value
        mini=min(mini,a[i]); //smallest value
    }
    return {mini,maxi};
}
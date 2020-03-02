// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;


// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.

vector<long long>ch;
void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        ch.push_back(stoll(a));
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

// Driver Code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str ;
        cin>>str;

        int n = str.size();
        permute(str, 0, n-1);
        bool ll=false;
        for(int i=0; i<ch.size(); i++)
        {
            if(ch[i]%60==0)
                ll =true;
        }
        if (ll==true)
            cout<<"red";
        else
            cout<<"cyan";
        ch.clear();
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

bool flag = false;

void recurrence(vector<int> &amount)
{
    int maxcredit = max_element(amount.begin(),amount.end()) - amount.begin();
    int maxdebit = min_element(amount.begin(),amount.end()) - amount.begin();

    if((amount[maxcredit]==0)&&(amount[maxdebit]==0))
        return;

    int m = min(amount[maxcredit],-amount[maxdebit]);
    amount[maxcredit] = amount[maxcredit] - m;
    amount[maxdebit] = amount[maxdebit] + m;

    flag = true;
    cout<<"Person "<<maxdebit+1<<" pays "<<m<<" to Person "<<maxcredit+1<<endl;

    recurrence(amount);
}

void mincashflow(vector<vector<int> > &v, int n)
{
    vector<int> amount(n,0);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            amount[i] = amount[i] + (v[j][i] - v[i][j]);

    recurrence(amount);
}

int main()
{
    int n,t,a,b,c;
    cout<<"Enter the Number of People: ";
    cin>>n;
    vector<vector<int> > v(n,vector<int>(n,0));
    cout<<"Enter the Number of Transactions: ";
    cin>>t;
    cout<<"Enter the Transactions in the following Format"<<endl;
    cout<<"Person who owes money      Person who is owed money      Amount"<<endl;
    for(int i=0; i<t; i++)
    {
        cin>>a>>b>>c;
        v[a-1][b-1] = v[a-1][b-1] + c;
    }

    mincashflow(v,n);
    if(!flag)
        cout<<"No need of any transactions";
}

//
//  main.cpp
//  nik codeforces problems
//
//  Created by PREEYADARSHEE DEV on 15/06/18.
//  Copyright © 2018 PREEYADARSHEE DEV. All rights reserved.
//
// train hard win easy :D
// by the way nik is love
// nik is motivation
// going off the grid for some time
//
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define f(i,n) fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n) rf(i,n,0)
#define inf (ll)1<<60
#define eps 0.000000001
#define endl '\n'
using namespace std;
vector<int> adj[3628801];
map<string,int>mt;
bitset<3628801> vis;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // lets fuck bfs anf dfs
    string s="abcdefghij";
    int k=1;
    do
    {
        mt.insert(mp(s,k++));  // initializing all the nodes
    }
    while(next_permutation(s.begin(),s.end()));
    auto itr=mt.begin();
    while(itr!=mt.end())
    {
        string s=itr->first;
        for(int i=0;i<10;i++)
        {
            for(int j=i+1;j<10;j++)
            {
                int id=j;
                reverse(s.begin()+i,s.begin()+j+1);
                auto itk=mt.find(s);
                adj[itr->second].pb(itk->second); // inserting all the edges in the adjacancy matrix
                id=j;
                reverse(s.begin()+i,s.begin()+j+1);
            }
        }
        itr++;
    }
    while(1)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1=="*"&&s2=="*")
            return 0;
        int sour=mt.find(s1)->second;  // source
        int dest=mt.find(s2)->second;  // destination
        queue<pair<int,int>>q;
        q.push(mp(sour,0));
        vis.reset();
        vis[sour]=1;
        while(vis[dest]==0)
        {
            auto v=q.front();
            q.pop();
            for(auto i:adj[v.ff])
            {
                if(vis[i]==0)
                {
                    if(i==dest)
                    {
                        cout<<v.ss+1<<endl;
                        vis[dest]=1;
                        break;
                    }
                    q.push(mp(i,v.ss));
                    vis[i]=1;
                }
            }
        }
    }
}

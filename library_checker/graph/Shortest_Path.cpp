#include <bits/stdc++.h>
#include <atcoder/all>
#include <functional>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using mint=modint1000000007;
auto INF_int=numeric_limits<int>::max();
auto INF_ll=numeric_limits<ll>::max();

int N,M,s,t;
vector<pair<int,ll>> G[500009];
ll dist[500009];
bool vis[500009];
int save[500009];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N>>M>>s>>t;
    for(int i = 0; i < N; ++i)
    {
        dist[i]=INF_ll;
        save[i]=-1;
    }
    while(M--)
    {
        ll a,b,c;cin>>a>>b>>c;
        G[a].push_back({b,c});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty())
    {
        auto [_,v]=pq.top();pq.pop();
        if(vis[v])continue;
        vis[v]=true;
        for(auto [u,cost]: G[v])
        {
            if(vis[u])continue;
            if(dist[u]>dist[v]+cost)
            {
                dist[u]=dist[v]+cost;
                save[u]=v;
                pq.push({dist[u],u});
            }
        }
    }
    if(!vis[t])cout<<-1<<endl;
    else
    {
        vector<int> path;
        for(int u=t; u!=-1;u=save[u])path.push_back(u);
        reverse(path.begin(),path.end());
        cout<<dist[t]<<" "<<path.size()-1<<endl;
        for(int i = 0; i < path.size()-1; ++i)
        {
            cout<<path[i]<<" "<<path[i+1]<<endl;
        }
    }
}
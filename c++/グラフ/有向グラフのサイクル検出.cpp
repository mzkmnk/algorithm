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

//グラフのサイクル検出

bool dfs(int u, unordered_map<int,vector<int>>& graph, unordered_map<int,int>& color, unordered_map<int,int>& parent, vector<int>& cycle)
{
    color[u]=1;
    for(int v:graph[u])
    {
        if(color[v]==1)
        {
            int tmp=u;
            while(tmp!=v)
            {
                cycle.push_back(tmp);
                tmp=parent[tmp];
            }
            cycle.push_back(v);
            //状況によってはサイクルの最後の要素を削除する必要がある
            cycle.push_back(u);
            reverse(cycle.begin(),cycle.end());
            return true;
        }
        if(color[v]==0)
        {
            parent[v]=u;
            if(dfs(v,graph,color,parent,cycle))return true;
        }
    }
    color[u]=2;
    return false;   
}

vector<int> find_cycle(unordered_map<int,vector<int>>& graph)
{
    unordered_map<int,int> color;
    unordered_map<int,int> parent;
    vector<int> cycle;
    //初期化　0:未訪問　1:訪問済み　2:訪問済みでサブツリーに含まれる
    for(auto& [k,v]:graph)color[k]=0;

    //未訪問からDFSを開始
    for(auto& [k,v]:graph)
    {
        if(color[k]==0)if(dfs(k,graph,color,parent,cycle))return cycle;
    }
    return {};
}
int N,M;
unordered_map<int,vector<int>> graph;


//-----サンプルコード-----
//cycleの中身は頂点番号
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

    map<pair<int,int>,int> edges;
    cin>>N>>M;
    for(int i = 0; i < M; ++i)
    {
        int u,v;cin>>u>>v;
        edges[{u,v}]=i;
        graph[u].push_back(v);
    }
    auto cycle=find_cycle(graph);
    if(cycle.empty())cout<<"-1"<<endl;
    else
    {
        cout<<cycle.size()-1<<endl;
        for(int i = 0; i < cycle.size()-1; i++)
        {
            cout<<edges[{cycle[i],cycle[i+1]}]<<endl;
        }
    }
}
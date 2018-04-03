import sys

sys.setrecursionlimit(200000)

def iLn():
    return map(int,filter(lambda x:x!='',raw_input().split(' ')))

[V,E]= iLn()
adj = [()]*(V+1)
adj_ = [()]*(V+1)
end=V
start=1

for i in range(E):
    [u,v,p,q]=iLn()
    adj[u]=adj[u]+((v,p,q),)
    adj_[v]=adj_[v]+((u,p,q),)

dis0=[0]*(V+1)
dis1=[0]*(V+1)
def dfs(e,n,dis,depth):
    depth=depth+1
    print(depth*" "+"dfs("+str(e)+" "+str(n)+" "+")")
    visited[e]=1
    for a in adj_[e]:
        v=a[0]
        d = dis[e] + a[n+1]

        if visited[v] and (d >= dis[v]):
            continue
        else:
            dis[v]=d
            if v == start:
                continue
            dfs(v,n,dis,depth)
    depth=depth-1
    return
visited=[0]*(V+1)
dfs(end,1,dis1,-1)

visited=[0]*(V+1)
dfs(end,0,dis0,-1)

print("OK")

def df(e):
    visited[e]=1
    for (v,p,q) in adj[e]:
        c=cost[e]
        if dis0[e]-p != dis0[v]:
            c=c+1
        if dis1[e]-q != dis1[v]:
            c=c+1
        if visited[v] and c>=cost[v]:
            continue
        else:
            cost[v]=c
            if v == end:
                continue
            df(v)
    return

visited=[0]*(V+1)
cost=[0]*(V+1)

df(start)
# print(dis0)
# print(dis1)
# print(adj_)
print(cost[end])

bool dfs(int v,int c)
{
  vis[v]=1;
  col[v]=c;
  for(int child :ae[v])
  {
    if(vis[child]==0)
    {
      if(dfs(child,c^1)==false)
        return false;
    }
    else
    {
      if(col[v]==col[child])
      return false;
    }
  }
  return true;
}

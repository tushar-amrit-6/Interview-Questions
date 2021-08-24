deque<int>dq;
int cap;
map<int,deque<int>::iterator>ma;
void refer(int x)
{
  if(ma.find(x)==ma.end())
  {
    if(dq.size()==cap)
    {
      int last = dq.back();
      dq.pop_back();
      ma.erase(last);
    }
  }
  else{
    dq.erase(ma[x]);
  }
  dq.push_front(x);
  ma[x]=dq.begin();
}

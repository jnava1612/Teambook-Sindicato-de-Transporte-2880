#define clr(a,h)    memset(a,(h),sizeof(a))

int BIT[tam];

void update(int pos, int val)
{
  pos++;
  while(pos < 200010)
  {
    BIT[pos] += val;
    pos += (pos & -pos);
  }
}

int query(int pos)
{
  pos++;
  int res = 0;
  while(pos > 0)
  {
    res += BIT[pos];
    pos -= (pos & -pos);
  }
  return res;
}

int main()
{
  clr(BIT,0);
  for(int i = n - 1; i >=0; i--)
  {
    inv +=query(a[i]);
    update(a[i],1);
  }
}

//to update all the values in a range [i,j] the following implementation is used

range_update(i,j,val) = update(i,val); update(j+1,-val);

//to find the range result of a range [i,j] for a Range Update Range Query

//rsq(1,j) = rupq.point_query(j)*j-purq.rsq(j)

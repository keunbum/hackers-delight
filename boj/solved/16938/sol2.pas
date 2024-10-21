{$R-,S-,Q-,I-,O+}
var
  n,l,r,x,i,ans: int32;
  a: array[0..15] of int32;

procedure DFS(v,cnt,sum,min,max: int32);
begin
  if v = n + 1 then
  begin
    if (cnt >= 2) and (l <= sum) and (sum <= r) and (max-min >= x) then
      inc(ans);
    exit;
  end;
  DFS(v+1,cnt,sum,min,max);
  if a[v] < min then min:=a[v];
  if a[v] > max then max:=a[v];
  DFS(v+1,cnt+1,sum+a[v],min,max);
end;

begin
  read(n,l,r,x);
  for i:=1 to n do read(a[i]);
  ans:=0;
  DFS(1,0,0,int32(1e7),0);
  writeln(ans);  
end.

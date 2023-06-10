{$R-,S-,Q-,I-,O+}
var
  n,m,i,j,k,sum,ans,x: longint;
  a: array[0..30,0..30] of longint;

function max(a,b: longint): longint;
begin
  if a > b then max:=a
  else max:=b
end;

begin
  read(n,m);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  ans:=0;
  for i:=1 to m do
    for j:=i+1 to m do
      for k:=j+1 to m do
      begin
        sum:=0;
        for x:=1 to n do
          sum += max(a[x,i],max(a[x,j],a[x,k]));
        ans:=max(ans,sum);
      end;
  writeln(ans);
end.

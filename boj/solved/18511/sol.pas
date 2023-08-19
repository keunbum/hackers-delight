{$R-,S-,Q-,I-,O+}
var
  n,k,i,ans: longint;
  a: array[0..3] of longint;

procedure DFS(v: longint);
var
  i: longint;
begin
  if v > n then exit;
  if v > ans then ans:=v;
  for i:=1 to k do DFS(v*10+a[i]);
end;

begin
  read(n,k);
  for i:=1 to k do read(a[i]);
  ans:=0;
  DFS(0);
  writeln(ans);
end.

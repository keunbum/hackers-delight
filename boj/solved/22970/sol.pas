{$R-,S-,Q-,I-,O+}
var
  n,i,j,cur,ans: longint;
  a: array[0..5000] of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  ans:=1;
  for i:=1 to n do
  begin
    j:=i-1;
    while (j >= 1) and (a[j] < a[j+1]) do dec(j);
    cur:=i-j;
    j:=i+1;
    while (j <= n) and (a[j-1] > a[j]) do inc(j);
    inc(cur,j-i-1);
    if cur > ans then ans:=cur;
  end;
  writeln(ans);
end.

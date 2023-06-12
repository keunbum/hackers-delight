{$R-,S-,Q-,I-,O+}
var
  n,i,j,ans: int16;
  a,L,R: array[0..5000] of int16;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  L[1]:=1;
  R[n]:=1;
  for i:=2 to n do
  begin
    if a[i-1] < a[i] then L[i]:=L[i-1]+1
    else L[i]:=1;
    j:=n+1-i;
    if a[j] > a[j+1] then R[j]:=R[j+1]+1
    else R[j]:=1;
  end;
  ans:=1;
  for i:=1 to n do
    if L[i]+R[i]-1 > ans then ans:=L[i]+R[i]-1;
  writeln(ans);
end.

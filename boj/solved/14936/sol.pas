{$R-,S-,Q-,I-,O+}
var
  i,j,k,n,m,ans: longint;
begin
  read(n,m);
  ans:=0;
  for i:=0 to longint(n >= 1) do
    for j:=0 to longint(n >= 2) do
      for k:=0 to longint(n >= 3) do
        inc(ans,longint((((n+1) shr 1)*i+(n shr 1)*j+((n+2) div 3)*k) <= m));
  writeln(ans);
end.

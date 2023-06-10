{$R-,S-,Q-,I-,O+}
var
  n,m,i,j,a,pre,_: int32;
  res: array[0..1000] of int32;
  dp: array[0..1000,0..9] of boolean;
begin
  for j:=1 to 9 do dp[0][j]:=True;
  read(n);
  for i:=1 to n do
  begin
    read(m);
    for _:=1 to m do
    begin
      read(a);
      for j:=1 to 9 do
        if a <> j then dp[i,a]:=dp[i,a] or dp[i-1,j];
    end;
  end;
  pre:=0;
  for i:=n downto 1 do
    for j:=1 to 9 do
      if (j <> pre) and dp[i,j] then
      begin
        pre:=j;
        res[i]:=j;
        break;
      end;
  if res[n] = 0 then writeln(-1)
  else for i:=1 to n do writeln(res[i]);
end.

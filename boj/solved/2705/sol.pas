{$R-,S-,Q-,I-,O+}
const MAXN = 1000;
var
  i,n,x: int32;
  dp: array[0..MAXN] of int32;
begin
  dp[0]:=1;
  dp[1]:=1;
  for i:=2 to MAXN do
    dp[i]:=dp[i-2]+dp[i div 2];
  read(n);
  for i:=1 to n do
  begin
    read(x);
    writeln(dp[x]);
  end;
end.
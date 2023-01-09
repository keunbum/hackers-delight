{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  n,i,j,cost: longint;
  s: ansistring;
  idx: array[0..127] of longint;
  dp: array[0..1001] of longint;
begin
  for i:=1 to 3 do idx[ord('BOJ'[i])]:=i-1;
  readln(n);
  readln(s);
  for i:=1 to n do dp[i]:=inf;
  dp[n]:=0;
  for i:=n-1 downto 1 do
    for j:=n downto i+1 do
      if (idx[ord(s[i])]+1) mod 3 = idx[ord(s[j])] then
        begin
          cost:=(j-i)*(j-i)+dp[j];
          if cost < dp[i] then dp[i]:=cost;
        end;
  if dp[1] = inf then writeln(-1)
  else writeln(dp[1]);
end.

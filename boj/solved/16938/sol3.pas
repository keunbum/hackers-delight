{$R-,S-,Q-,I-,O+}
var
  n,l,r,x,i,j,m,t,bs,sum,ans: int32;
  a,b: array[0..15] of int32;
begin
  read(n,l,r,x);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=1 to n-i do
      if a[j] > a[j+1] then
      begin
        t:=a[j];
        a[j]:=a[j+1];
        a[j+1]:=t;
      end;
  ans:=0;
  for bs:=0 to (1 shl n) do
  begin
    m:=0;
    sum:=0;
    for i:=1 to n do
      if boolean((bs shr (i-1)) and 1) then
      begin
        inc(sum,a[i]);
        b[m]:=a[i];
        inc(m);
      end;
    if (m >= 2) and (l <= sum) and (sum <= r) and (b[m-1]-b[0] >= x) then
      inc(ans);
  end;
  writeln(ans);
end.

{$R-,S-,Q-,I-,O+}
var
  n,l,r,x,i,bs,cnt,max,min,sum,ans: int32;
  a: array[0..15] of int32;
begin
  read(n,l,r,x);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for bs:=0 to (1 shl n) do
  begin
    cnt:=0;
    max:=0;
    min:=round(1e7);
    sum:=0;
    for i:=1 to n do
      if (bs shr (i-1)) and 1 = 1 then
      begin
        inc(cnt);
        if a[i] > max then max:=a[i];
        if a[i] < min then min:=a[i];
        inc(sum,a[i]);
      end;
    if (cnt >= 2) and (l <= sum) and (sum <= r) and (max-min >= x) then
      inc(ans);
  end;
  writeln(ans);
end.

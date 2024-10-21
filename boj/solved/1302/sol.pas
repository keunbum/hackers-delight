{$R-,S-,Q-,I-,O+}
var
  n,i,best,x,j,cnt: longint;
  a: array[0..1000] of ansistring;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  best:=0;
  x:=1;
  for i:=1 to n do
  begin
    cnt:=0;
    for j:=1 to n do inc(cnt,longint(a[j] = a[i]));
    if (cnt > best) or ((cnt = best) and (a[i] < a[x])) then
    begin
      best:=cnt;
      x:=i;
    end;
  end;
  writeln(a[x]);
end.

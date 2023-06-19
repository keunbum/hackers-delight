{$R-,S-,Q-,I-,O+}
var
  c,_,n,i,sum,cnt: longint;
  a: array[0..1000] of longint;
begin
  read(c);
  for _:=1 to c do
  begin
    read(n);
    sum:=0;
    for i:=1 to n do
    begin
      read(a[i]);
      inc(sum,a[i]);
    end;
    cnt:=0;
    for i:=1 to n do
      inc(cnt,longint(a[i] * n > sum));
    writeln(cnt/n*100 : 0 : 3,'%');
  end;
end.

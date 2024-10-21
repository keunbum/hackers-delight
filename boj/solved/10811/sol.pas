{$R-,S-,Q-,I-,O+}
var
  n,m,_,i,j,t: longint;
  a: array[0..100] of longint;
begin
  read(n,m);
  for i:=1 to n do a[i]:=i;
  for _:=1 to m do
  begin
    read(i,j);
    while i < j do
    begin
      t:=a[i];
      a[i]:=a[j];
      a[j]:=t;
      inc(i);
      dec(j);
    end;
  end;
  for i:=1 to n do write(a[i],' ');
end.

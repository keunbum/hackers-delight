{$R-,S-,Q-,I-,O+}
var
  n,m,_,i,x,y,z: longint;
  a: array[0..100] of longint;
begin
  read(n,m);
  for _:=1 to m do
  begin
    read(x,y,z);
    for i:=x to y do a[i]:=z;
  end;
  for i:=1 to n do write(a[i],' ');
end.

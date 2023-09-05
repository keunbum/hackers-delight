{$R-,S-,Q-,I-,O+}
var
  n,m,i,x,ans: longint;
  pos: array[0..1000] of longint;
begin
  read(n,m);
  for i:=1 to n do
  begin
    read(x);
    pos[x]:=i;
  end;
  ans:=0;
  for i:=1 to m do
  begin
    read(x);
    if pos[x] > m then inc(ans);
  end;
  writeln(ans);
end.

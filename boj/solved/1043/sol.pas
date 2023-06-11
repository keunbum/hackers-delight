{$R-,S-,Q-,I-,O+}
var
  found: boolean;
  n,m,t,_,x,i,j,ans: longint;
  good,know: array[0..50] of boolean;
  sz: array[0..50] of longint;
  a: array[0..50,0..50] of longint;
begin
  read(n,m);
  read(t);
  for _:=1 to t do
  begin
    read(x);
    know[x]:=True;
  end;
  for i:=1 to m do
  begin
    read(sz[i]);
    for j:=1 to sz[i] do read(a[i,j]);
  end;
  for i:=1 to m do good[i]:=True;
  while True do
  begin
    found:=False;
    for i:=1 to m do
      if good[i] then
      begin
        for j:=1 to sz[i] do good[i]:=good[i] and not know[a[i,j]];
        if not good[i] then
        begin;
          found:=True;
          for j:=1 to sz[i] do know[a[i,j]]:=True;
        end;
      end;
    if not found then break;
  end;
  ans:=0;
  for i:=1 to m do inc(ans,longint(good[i]));
  writeln(ans);
end.

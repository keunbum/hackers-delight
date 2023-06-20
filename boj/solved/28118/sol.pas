{$R-,S-,Q-,I-,O+}
var
  i,n,m,_,x,y: longint;
  p: array[0..40] of longint;

function Get(x: longint): longint;
begin
  if x = p[x] then Get:=x else
  begin
    p[x]:=Get(p[x]);
    Get:=p[x];
  end;
end;

function Unite(x,y: longint): longint;
begin
  x:=Get(x);
  y:=Get(y);
  if x = y then Unite:=0 else
  begin
    p[x]:=y;
    Unite:=1;
  end
end;

begin
  read(n,m);
  for i:=1 to n do p[i]:=i;
  for _:=1 to m do
  begin
    read(x,y);
    dec(n,Unite(x,y));
  end;
  writeln(n-1);
end.

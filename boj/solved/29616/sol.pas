{$R-,S-,Q-,I-,O+}
var
  p,t,g,i,n,max,v: longint;
  s: array[0..2] of longint;
  a: array[0..2,0..100] of longint;

function GCD(a,b: longint): longint;
var
  t: longint;
begin
  while b > 0 do
  begin
    t:=a mod b;
    a:=b;
    b:=t;
  end;
  GCD:=a;
end;

begin
  read(n,p);
  for t:=1 to 2 do
  begin
    g:=0;
    for i:=1 to n do
    begin
      read(a[t,i]);
      g:=GCD(g,a[t,i]);
    end;
    s[t]:=0;
    for i:=1 to n do
    begin
      a[t,i]:=a[t,i] div g;
      inc(s[t],a[t,i]);
    end;
  end;
  max:=0;
  for i:=1 to n do
    if a[2,i] <> 0 then
    begin
      v:=(a[1,i]+a[2,i]-1) div a[2,i];
      if v > max then max:=v;
    end;
  writeln(s[1],' ',int64(max)*s[2]);
end.

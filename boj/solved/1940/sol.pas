{$R-,S-,Q-,I-,O+}
const MAX = round(1e5);
var
  n,m,ans,y,x: longint;
  was: array[0..MAX] of boolean;
begin
  read(n,m);
  ans:=0;
  fillchar(was,sizeof(was),False);
  while n > 0 do
  begin
    read(x);
    y:=m-x;
    if (y >= 1) and (y <= MAX) and was[y] then inc(ans);
    was[x]:=True;
    dec(n);
  end;
  writeln(ans);
end.

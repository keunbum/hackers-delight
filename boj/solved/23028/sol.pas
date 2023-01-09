{$R-,S-,Q-,I-,O+}
var
  n,i,x,y,a,b: int32;
begin
  readln(n,a,b);
  n:=8-n;
  for i:=1 to n do
  begin
    read(x,y);
    if x+y > 6 then y:=6-x;
    inc(a,3*x);
    inc(b,3*(x+y));
  end;
  if (a >= 66) and (b >= 130) then writeln('Nice')
  else writeln('Nae ga wae');
end.
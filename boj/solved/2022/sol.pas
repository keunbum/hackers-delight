{$R-,S-,Q-,I-,O+}
var
  i: longint;
  x,y,c,low,high,mid,hx,hy,d: double;  
begin
  read(x,y,c);
  if x < y then
  begin
    d:=y; y:=x; x:=d;
  end;
  low:=0;
  high:=y;
  for i:=1 to 100 do
  begin
    mid:=(low+high)*0.5;
    hx:=sqrt(x*x-mid*mid);
    hy:=sqrt(y*y-mid*mid);
    d:=hx*hy/(hx+hy);
    if d < c then high:=mid
    else low:=mid
  end;
  writeln(0.5*(low+high):0:3);
end.

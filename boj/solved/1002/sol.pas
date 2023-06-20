{$R-,S-,Q-,I-,O+}
var
  tt,_,x1,y1,r1,x2,y2,r2,dd,rra,rrs,ans: longint;
begin
  read(tt);
  for _:=1 to tt do
  begin
    read(x1,y1,r1,x2,y2,r2);
    dd:=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    rra:=(r1+r2)*(r1+r2);
    rrs:=(r1-r2)*(r1-r2);
    if dd = 0 then 
      if rrs = 0 then 
        if r1 = 0 then ans:=1
        else ans:=-1
      else ans:=0 else
    if (dd < rrs) or (dd > rra) then ans:=0 else
    if (dd = rrs) or (dd = rra) then ans:=1 else
    if dd < rra then ans:=2;
    writeln(ans);
  end;
end.

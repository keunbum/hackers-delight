{$R-,S-,Q-,I-,O+}
var
  mw,mb,tw,tb,pw,pb,x,y: longint;

function min(a,b: longint): longint;
begin
  if a < b then min:=a
  else min:=b;
end;

begin
  read(mw,mb,tw,tb,pw,pb);
  x:=min(tw,min(mb,pb));
  y:=min(tb,min(mw,pw));
  if x = y then writeln(2*x)
  else writeln(2*min(x,y)+1);
end.

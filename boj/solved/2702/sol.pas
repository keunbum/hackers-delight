{$R-,S-,Q-,I-,O+}
var
  qq,tt,a,b,g: int32;

function GCD(a,b: int32): int32;
var
  t: int32;
begin
  while b > 0 do
  begin
    t:=b;
    b:=a mod b;
    a:=t;
  end;
  GCD:=a;
end;

begin
  read(tt);
  for qq:=1 to tt do
  begin
    read(a,b);
    g:=GCD(a,b);
    writeln(a*b div g,' ',g);
  end;
end.

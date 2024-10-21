{$R-,S-,Q-,I-,O+}
var
  qq,tt,a,b,g: int32;

function GCD(a,b: int32): int32;
begin
  if b = 0 then GCD:=a
  else GCD:=GCD(b,a mod b);
end;

begin
  read(tt);
  for qq:=1 to tt do
  begin
    read(a,b);
    g:=GCD(a,b);
    writeln(a * b div g,' ',g);
  end;
end.

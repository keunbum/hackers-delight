{$R-,S-,Q-,I-,O+}
var
  n: int32;
begin
  read(n);
  if n = 1 then writeln(0)
  else writeln((n*n+n mod 2) div 2);
end.

{$R-,S-,Q-,I-,O+}
var
  n,i,x,max,min: int32;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(x);
    inc(max,abs(x));
    inc(min,-abs(x));
  end;
  writeln(max-min);
end.

{$R-,S-,Q-,I-,O+}
var
  n,x,y: int32;
begin
  read(n,x,y);
  writeln(4-(int32(x = 1)+int32(x = n)+int32(y = 1)+int32(y = n)));
end.

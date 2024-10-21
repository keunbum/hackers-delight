{$R-,S-,Q-,I-,O+}
var
  d,vf,vg,da2,db2: int32;
begin
  da2:=144;
  while not eof do
  begin
    readln(d,vf,vg);
    db2:=da2+d*d;
    writeln('NS'[int32(da2*vg*vg >= db2*vf*vf)+1]);
  end;
end.
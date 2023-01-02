{$R-,S-,Q-,I-,O+}
var
  h,w,ha,wa,hb,wb,i,j,cnt: int32;
  s: string;
begin
  readln(h,w,ha,wa,hb,wb);
  cnt:=0;
  for i:=1 to h do
  begin
    readln(s);
    for j:=1 to w do
      inc(cnt,int32(s[j] = 'P'));
  end;
  writeln(int32(cnt <> hb*wb));
end.

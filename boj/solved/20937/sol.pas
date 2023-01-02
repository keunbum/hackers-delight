{$R-,S-,Q-,I-,O+}
const MAX = round(5e4);
var
  i,n,c,mx: int32;
  cnt: array[0..MAX] of int32;
begin
  read(n);
  for i:=1 to n do
  begin
    read(c);
    inc(cnt[c]);
  end;
  mx:=0;
  for i:=1 to MAX do
    if cnt[i] > mx then mx:=cnt[i];
  writeln(mx);
end.

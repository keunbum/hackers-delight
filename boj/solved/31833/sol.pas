{$R-,S-,Q-,I-,O+}
var
  n,t,i,x,v: int32;
  res: array[1..2] of int64;
begin
  readln(n);
  for t:=1 to 2 do
  begin
    res[t]:=0;
    for i:=1 to n do
    begin
      read(x);
      if x < 10 then v:=10
      else v:=100;
      res[t]:=res[t]*v+x;
    end;
  end;
  if res[1] < res[2] then writeln(res[1])
  else writeln(res[2]);
end.

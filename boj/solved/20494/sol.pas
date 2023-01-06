{$R-,S-,Q-,I-,O+}
var
  n,i,ans: int32;
  s: string;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(s);
    inc(ans,length(s));
  end;
  writeln(ans);
end.

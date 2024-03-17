{$R-,S-,Q-,I-,O+}
var
  n,i,x,max_v,max_c,ans: longint;
begin
  read(n);
  ans:=0;
  max_v:=0;
  max_c:=0;
  for i:=1 to n do
  begin
    read(x);
    if max_v > x then max_c += 1 else
    begin
      max_v:=x;
      max_c:=0;
    end;
    if max_c > ans then ans:=max_c;
  end;
  writeln(ans);
end.
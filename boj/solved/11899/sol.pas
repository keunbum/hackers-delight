{$R-,S-,Q-,I-,O+}
var
  n,ans,i,balance: longint;
  s: ansistring;
begin
  read(s);
  n:=length(s);
  balance:=0;
  ans:=0;
  for i:=1 to n do
  begin
    if s[i] = '(' then
    begin
      if balance < 0 then
      begin
        dec(ans,balance);
        balance:=0;
      end;
      inc(balance);
    end
    else dec(balance);
  end;
  if balance < 0 then
  begin
    dec(ans,balance);
    balance:=0;
  end;
  writeln(ans+balance);
end.

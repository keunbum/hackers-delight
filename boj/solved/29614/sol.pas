{$R-,S-,Q-,I-,O+}
var
  n,i,cnt: longint;
  sum: double;
  s: ansistring;
begin
  read(s);
  n:=length(s);
  i:=1;
  sum:=0;
  cnt:=0;
  while i <= n do
  begin
    if s[i] <> 'F' then sum += 4.0-(Ord(s[i])-Ord('A'));
    inc(i);
    inc(cnt);
    if (i <= n) and (s[i] = '+') then
    begin
      sum += 0.5;
      inc(i);
    end;
  end;
  writeln(sum/cnt : 0 : 20);
end.

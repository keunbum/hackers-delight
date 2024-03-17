{$R-,S-,Q-,I-,O+}
const strs: array[1..3] of ansistring = ('pi', 'ka', 'chu');
var
  ok: boolean;
  i,j,sz,n: longint;
  s,t: ansistring;
begin
  read(s);
  i:=1;
  n:=length(s);
  while i <= n do
  begin
    ok:=False;
    for j:=1 to 3 do
    begin
      sz:=length(strs[j]);
      t:=s[i..i+sz-1];
      if t = strs[j] then
      begin
        ok:=True;
        i += sz;
        break;
      end;
    end;
    if not ok then
    begin
      writeln('NO');
      exit;
    end;
  end;
  writeln('YES')
end.
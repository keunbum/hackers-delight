{$R-,S-,Q-,I-,O+}
var
  tt,qq,w,h,_: int32;
  s: ansistring;
begin
  read(tt);
  for qq:=1 to tt do
  begin
    read(w,h);
    setlength(s, w);
    fillchar(s[1],w,'X');
    for _:=1 to h do
      writeln(s);
    writeln;
  end;
end.
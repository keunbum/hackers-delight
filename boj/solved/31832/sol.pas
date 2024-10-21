{$R-,S-,Q-,I-,O+}
var
  ch: char;
  notdigit: boolean;
  n,_,upper,lower: int32;
  s: ansistring;
begin
  readln(n);
  for _:=1 to n do
  begin
    readln(s);
    upper:=0;
    lower:=0;
    notdigit:=False;
    for ch in s do
    begin
      if ch in ['A'..'Z'] then inc(upper);
      if ch in ['a'..'z'] then inc(lower);
      notdigit:=notdigit or not (ch in ['0'..'9']);
    end;
    if (upper <= lower) and (length(s) <= 10) and notdigit then
    begin
      writeln(s);
      halt;
    end;
  end;
  assert(False);
end.

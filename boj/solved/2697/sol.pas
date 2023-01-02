{$R-,S-,Q-,I-,O+}
var
  ch: char;
  qq,tt,n,k,p,min_p: int32;
  s: ansistring;
begin
  readln(tt);
  for qq:=1 to tt do
  begin
    readln(s);
    n:=length(s);
    k:=n;
    while (k > 1) and (s[k-1] >= s[k]) do dec(k);
    if k = 1 then
    begin
      writeln('BIGGEST');
      continue;
    end;
    min_p:=0;
    for p:=n downto k do
      if (s[k-1] < s[p]) and ((min_p = 0) or (s[p] < s[min_p])) then
        min_p:=p;
    ch:=s[k-1];
    s[k-1]:=s[min_p];
    s[min_p]:=ch;
    while k < n do
    begin
      ch:=s[k];
      s[k]:=s[n];
      s[n]:=ch;
      inc(k);
      dec(n);
    end;
    writeln(s);
  end;
end.

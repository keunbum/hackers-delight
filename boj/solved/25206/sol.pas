{$R-,S-,Q-,I-,O+}
var        
  s,_,p,i,n: longint;
  ln,g: ansistring;
  q: double;
begin
  p:=0;
  q:=0.0;
  for _:=1 to 20 do
  begin
    readln(ln);
    i:=0;
    while ln[i + 1] <> '.' do inc(i);
    s:=Ord(ln[i])-Ord('0');
    while not (ln[i] in ['A'..'Z']) do inc(i);
    g:='';
    n:=length(ln);
    while i <= n do
    begin
      g:=g+ln[i];
      inc(i);
    end;
    if g <> 'P' then
    begin
      p += s;
      q += s*(Pos(g[1],'FDCBA')-1+0.5*longint((length(g) > 1) and (g[2] = '+')));
    end;    
  end;
  writeln(q/p:0:17);
end.

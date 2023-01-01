{$R-,S-,Q-,I-,O+}
var
  hh,mm,tt,st,d: int32;

procedure Get(var x: int32);
var
  ch: char;
begin
  x:=0;
  read(ch);
  while not (ch in['0'..'9']) do read(ch);
  while ch in ['0'..'9'] do
  begin
    x:=x*10+ord(ch)-ord('0');
    read(ch);
  end;
end;

function DFS(st,d: int32): int32;
var
  v1, v2: int32;
begin            
  if d <= 0 then
  begin
    DFS:=0;
    exit;
  end;
  v1:=round(1e9);
  if st < 600 then v1:=DFS(600, d-(600-st))+5000;
  v2:=DFS((st+60) mod 1440,d-60)+1000;
  if v1 < v2 then DFS:=v1
  else DFS:=v2;
end;

begin
  readln(tt);
  while tt > 0 do
  begin
    Get(hh);
    Get(mm);
    Get(d);
    st:=((hh+2)*60+mm) mod 1440;
    writeln(DFS(st, d));
    dec(tt);
  end;
end.

{$R-,S-,Q-,I-,O+}
var
  cur: boolean;
  tgt,op,v: char;
  n,i,d,ans: int32;
  a: array[0..1999] of char;

procedure ReadChar(var ch: char);
begin
  read(ch);
  while (ch = ' ') or (ch = #10) or (ch = #13) do read(ch);
end;

function Encode(ch: char): boolean;
begin
  Encode:=(ch = 'T');
end;

function Calc(v: boolean; op: char; u: boolean): boolean;
begin
  if op = '&' then Calc:=v and u;
  if op = '|' then Calc:=v or u;
end;

begin
  readln(n);
  for i:=1 to n do
    ReadChar(a[i]);
  ReadChar(tgt);
  if n = 1 then
  begin
    writeln(int32(a[1] <> tgt));
    halt;
  end;
  cur:=Encode(a[1]);
  i:=3;
  while i <= n-2 do
  begin
    cur:=Calc(cur,a[i-1],Encode(a[i]));
    i += 2
  end;
  ans:=3;
  for op in '&|' do
    for v in 'FT' do
      if Calc(cur,op,Encode(v)) = Encode(tgt) then
      begin
        d:=int32(op <> a[n-1]) + int32(v <> a[n]);
        if d < ans then ans:=d;
      end;
  writeln(ans);
end.

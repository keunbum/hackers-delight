{$R-,S-,Q-,I-,O+}
const
  MAX = round(1e4);
  DI: array[0..3] of int32 = (1, 0, -1, 0);
  DJ: array[0..3] of int32 = (0, 1, 0, -1);
var
  w,h,i,j,ni,nj,b,e,dir: int32;
  was: array[0..99,0..99] of boolean;
  s: array[0..99,0..100] of char;
  ret: array[0..1] of int32;
  qi,qj: array[0..MAX] of int32;
begin
  readln(w,h);
  for i:=0 to h-1 do readln(s[i]);
  ret[0]:=0;
  ret[1]:=0;
  fillchar(was,sizeof(was),False);
  for i:=0 to h-1 do
    for j:=0 to w-1 do
      if not was[i,j] then
      begin
        was[i,j]:=True;
        b:=0;
        qi[b]:=i;
        qj[b]:=j;
        e:=1;
        while b < e do
        begin
          for dir:=0 to 3 do
          begin
            ni:=qi[b]+DI[dir];
            nj:=qj[b]+DJ[dir];
            if (ni >= 0) and (nj >= 0) and (ni < h) and (nj < w) and (s[ni,nj] = s[qi[b],qj[b]]) and (not was[ni,nj]) then
            begin
              was[ni,nj]:=True;
              qi[e]:=ni;
              qj[e]:=nj;
              inc(e);
            end;
          end;
          inc(b);
        end;
        if s[i,j] = 'W' then inc(ret[0],e*e)
        else inc(ret[1],e*e);
      end;
  writeln(ret[0],' ',ret[1]);
end.

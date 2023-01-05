{$R-,S-,Q-,I-,O+}
var
  qq,n,i,j,s,e,t,cnt: int32;
  aux: array[0..47,0..99] of boolean;
  used: array[0..99] of boolean;
  order,es: array[0..99] of int32;
begin
  qq:=1;
  while True do
  begin
    read(n);
    if n = 0 then
      break;
    fillchar(aux,sizeof(aux),False);
    for i:=0 to n-1 do
    begin
      read(s,e);
      es[i]:=e;
      s:=s shl 1;
      e:=e shl 1;
      for j:=s to e-1 do
        aux[j][i]:=True;
    end;
    for i:=0 to n-1 do
      order[i]:=i;
    for i:=1 to n do
      for j:=0 to n-1-i do
        if es[order[j]] > es[order[j+1]] then
        begin
          t:=order[j];
          order[j]:=order[j+1];
          order[j+1]:=t;
        end;
    fillchar(used,sizeof(used),False);
    cnt:=0;
    for i:=16 to 47 do
      for j:=0 to n-1 do
        if aux[i][order[j]] and not used[order[j]] then
        begin
          used[order[j]]:=True;
          inc(cnt);
          break;
        end;
    writeln('On day ',qq,' Emma can attend as many as ',cnt,' parties.');
    inc(qq);
  end;
end.

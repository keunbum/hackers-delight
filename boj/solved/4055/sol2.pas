{$R-,S-,Q-,I-,O+}
var
  qq,n,i,j,t,ans: int32;
  s,e: array[0..100] of int32;
  used: array[0..48] of boolean;
begin
  qq:=1;
  while True do
  begin
    read(n);
    if n = 0 then
      break;
    for i:=1 to n do
    begin
      read(s[i],e[i]);
      s[i]:=s[i] shl 1;
      e[i]:=e[i] shl 1;
    end;
    for i:=1 to n do
      for j:=1 to n-i do
        if e[j] > e[j+1] then
        begin
          t:=e[j]; e[j]:=e[j+1]; e[j+1]:=t;
          t:=s[j]; s[j]:=s[j+1]; s[j+1]:=t;
        end;
    ans:=0;
    fillchar(used,sizeof(used),False);
    for i:=1 to n do
      for j:=s[i] to e[i]-1 do
        if not used[j] then
        begin
          used[j]:=True;
          inc(ans);
          break;
        end;
    writeln('On day ',qq,' Emma can attend as many as ',ans,' parties.');
    inc(qq);
  end;
end.

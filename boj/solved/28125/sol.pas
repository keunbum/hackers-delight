{$R-,S-,Q-,I-,O+}
const
  A = 'acijnot';
  B = '@[!;^07';
var
  _,n,tt,i,x,cnt: int32;
  s,ans,cur: string;
  mp: array[0..127] of char;
begin
  for i:=1 to length(A) do mp[Ord(B[i])]:=A[i];
  readln(tt);
  for _:=1 to tt do
  begin
    readln(s);
    n:=length(s);
    cnt:=0;
    ans:='';
    i:=1;
    while i <= n do
    begin
      x:=Ord(s[i]);
      if mp[x] <> #0 then
      begin
        ans += mp[x];
        Inc(cnt);
      end else
      if s[i] = '\' then
      begin
        cur:='';
        while s[i] = '\' do
        begin
          cur += s[i];
          Inc(i);
        end;
        ans += 'wv'[Byte(cur = '\')+1];
        Inc(cnt);
      end
      else ans += s[i]; 
      Inc(i);
    end;
    if 2*cnt < length(ans) then writeln(ans)
    else writeln('I don''t understand');
  end;
end.

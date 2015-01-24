program problem21;
const maxn=10000;
var f:array[0..maxn] of longint;
    i,ans:longint;
function calc(x:longint):longint;
 var i,s:longint;
 begin
     s:=0;
     for i:=1 to x-1 do
	if (x mod i=0) then s:=s+i;
     calc:=s;
 end;

begin
    f[0]:=0;
    for i:=1 to maxn do f[i]:=calc(i);
    ans:=0;
    for i:=1 to maxn do
	if (f[i]<=maxn) and (f[f[i]]=i) and (i<>f[i]) then ans:=ans+i;
    writeln(ans);
end.

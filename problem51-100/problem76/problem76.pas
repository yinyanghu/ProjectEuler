program problem76;
const maxn=100;
var f:array[0..maxn,0..maxn] of longint;
    k,total:longint;
procedure work(n,k:longint);
 var i,j:longint;
 begin
     f[0,0]:=1;
     for i:=1 to n do
	for j:=1 to i do f[i,j]:=f[i-1,j-1]+f[i-j,j];
 end;
 
begin
    work(maxn,maxn);
    total:=0;
    for k:=1 to maxn do total:=total+f[maxn,k];
    writeln(total-1);
end.
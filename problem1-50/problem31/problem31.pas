program problem31;
const n=8;
      w:array[1..n] of longint=(1,2,5,10,20,50,100,200);
      maxn=200;
var f:array[1..maxn] of qword;
    i,j:longint;
begin
    fillchar(f,sizeof(f),0);
    for i:=1 to n do f[w[i]]:=1;
    for i:=1 to maxn do
	for j:=1 to n do
	   if i>w[j] then f[i]:=f[i]+f[i-w[j]];
    for i:=1 to 20 do writeln(f[i]);
    writeln(f[maxn]);
end.
program problem81;
const n=80;
var a,f:array[1..n,1..n] of longint;
    i,j,k:longint;
function min(a,b:longint):longint;
 begin
     if a<b then min:=a else min:=b;
 end;

begin
    assign(input,'problem81.txt'); reset(input);
    for i:=1 to n do
	for j:=1 to n do read(a[i,j]);
    close(input);
    f[1,1]:=a[1,1];
    for i:=2 to n do f[1,i]:=f[1,i-1]+a[1,i];
    for i:=2 to n do f[i,1]:=f[i-1,1]+a[i,1];
    for i:=2 to n do
	for j:=2 to n do f[i,j]:=min(f[i-1,j],f[i,j-1])+a[i,j];
    writeln(f[n,n]);
end.

program problem8;
const maxn=1000;
var a:array[1..maxn] of longint;
    i,j,k,max:longint;
    ch:char;
begin
    assign(input,'problem8.txt'); reset(input);
    for i:=1 to maxn do begin
	read(ch);
	a[i]:=ord(ch)-48;
    end;
    close(input);
    max:=0;
    for i:=1 to maxn-4 do begin
        k:=1;
        for j:=i to i+4 do k:=k*a[j];
        if k>max then max:=k;
    end;
    writeln(max);
end.

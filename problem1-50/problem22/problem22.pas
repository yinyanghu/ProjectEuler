program problem22;
const maxn=6000;
var a:array[1..maxn] of string;
    i,j,k,n,ans:longint;
procedure sort(l,r:longint);
 var i,j:longint;
     x,y:string;
 begin
     i:=l; j:=r; x:=a[(l+r) div 2];
     repeat
        while a[i]<x do inc(i);
        while a[j]>x do dec(j);
        if i<=j then begin
	    y:=a[i]; a[i]:=a[j]; a[j]:=y;
	    inc(i); dec(j);
	end;
     until i>j;
     if l<j then sort(l,j);
     if i<r then sort(i,r);
 end;

begin
    assign(input,'problem22.txt'); reset(input);
    n:=0;
    while not eof do begin
	inc(n);
	readln(a[n]);
    end;
    close(input);
    sort(1,n);
    ans:=0;
    for i:=1 to n do begin
	k:=0;
	for j:=1 to length(a[i]) do k:=k+ord(a[i,j])-64;
	ans:=ans+k*i;
    end;
    writeln(ans);
end.

program problem13;
const maxn=52;
type arr=array[1..maxn] of longint;
var a,c:arr; 
    i,k:longint;
    s:string;
procedure plus(a,b:arr; var c:arr);
 var i,k:longint;
 begin
     k:=0;
     for i:=1 to maxn do begin
	 c[i]:=a[i]+b[i]+k;
	 k:=c[i] div 10;
	 c[i]:=c[i] mod 10;
     end;
 end;

procedure change(s:string; var a:arr);
 var i:longint;
 begin
     for i:=1 to 50 do a[i]:=ord(s[51-i])-48;
 end;

begin
    assign(input,'problem13.txt'); reset(input);
    fillchar(c,sizeof(c),0);
    for i:=1 to 100 do begin
	readln(s);
	change(s,a);
	plus(a,c,c);
    end;
    close(input);
    k:=maxn;
    while c[k]=0 do dec(k);
    for i:=0 to 9 do write(c[k-i]);
    writeln;
end.

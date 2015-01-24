program problem18;

const maxn=100;
var a,f:array[1..maxn,1..maxn] of longint;

    i,j,n:longint;

function max(a,b:longint):longint;

 begin

     if a>b then max:=a else max:=b;

 end;


begin

    assign(input,'problem18.txt'); reset(input);

    readln(n);

    for i:=1 to n do

       for j:=1 to i do read(a[i,j]);

    close(input);

    fillchar(f,sizeof(f),0);

    for i:=n downto 1 do

       for j:=1 to i do

         f[i,j]:=max(f[i+1,j],f[i+1,j+1])+a[i,j];

    writeln(f[1,1]);

end.
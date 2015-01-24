program problem11;
const n=20;
var a:array[1..n,1..n] of longint;
    s:array[1..8] of longint;
    i,j,k,max:longint;

function down(x,y:longint):longint;
 var k,i:longint;
 begin
     if x>17 then exit(-1);
     k:=1;
     for i:=0 to 3 do k:=k*a[x+i,y];
     down:=k;
 end;


function right(x,y:longint):longint;
 var k,i:longint;
 begin
     if y>17 then exit(-1);
     k:=1;
     for i:=0 to 3 do k:=k*a[x,y+i];
     right:=k;
 end;

function diagonlr(x,y:longint):longint;
 var k,i:longint;
 begin
     if (y>17) or (x>17) then exit(-1);
     k:=1;
     for i:=0 to 3 do k:=k*a[x+i,y+i];
     diagonlr:=k;
 end;

function diagonrl(x,y:longint):longint;
 var k,i:longint;
 begin
     if (x<4) or (y>17) then exit(-1);
     k:=1;
     for i:=0 to 3 do k:=k*a[x-i,y+i];
     diagonrl:=k;
 end;

begin
    assign(input,'problem11.txt'); reset(input);
    for i:=1 to n do
        for j:=1 to n do read(a[i,j]);
    close(input);
    max:=0;
    for i:=1 to n do
      for j:=1 to n do begin
          s[1]:=down(i,j);
          s[2]:=right(i,j);
          s[3]:=diagonlr(i,j);
          s[4]:=diagonrl(i,j);
          for k:=1 to 4 do
             if s[k]>max then max:=s[k];
      end;
    writeln(max);
end.

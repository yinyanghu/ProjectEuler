program problem6;
const n=100;
var i,a,b:longint;
begin
    a:=sqr(5050);
    b:=0;
    for i:=1 to n do b:=b+sqr(i);
    writeln(a-b);
end.

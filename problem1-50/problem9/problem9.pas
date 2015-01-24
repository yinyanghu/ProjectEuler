program problem9;
const maxn=1000;
var a,b,c:longint;
begin
    for a:=1 to maxn do
        for b:=a+1 to maxn do begin
            c:=maxn-a-b;
            if c>b then
               if (a*a+b*b=c*c) then begin
                   writeln(a,' ',b,' ',c,' ans=',a*b*c);
                   halt;
               end;
        end;
end.
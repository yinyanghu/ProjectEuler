program problem10;
const n=1000000;
var a:array[1..n] of boolean;
    i,j:longint;
    ans:qword;
begin
    fillchar(a,sizeof(a),true);
    a[1]:=false;
    i:=2;
    while i<sqrt(n) do begin
        while not a[i] do inc(i);
        j:=2;
        while (i*j<=n) do begin
            a[i*j]:=false;
            inc(j);
        end;
        inc(i);
    end;
    ans:=0;
    for i:=1 to n do
       if a[i] then ans:=ans+i;
    writeln(ans);
end.
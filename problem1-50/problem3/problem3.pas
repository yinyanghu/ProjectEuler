program problem3;
const n=317584931803;
var ans,i:longint;
    k:int64;
begin
    i:=1; ans:=0; k:=n;
    while k<>1 do begin
	inc(i);
	if k mod i=0 then begin
	    if i>ans then ans:=i;
	    while (k mod i=0) do k:=k div i;
	end;
    end;
    writeln(ans);
end.

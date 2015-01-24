program prepare;
var s:ansistring;
    i,k:longint;
begin
    assign(input,'problem22.txt'); reset(input);
    readln(s);
    close(input);
    assign(output,'problem22.out'); rewrite(output);
    delete(s,1,1);
    delete(s,length(s),1);
    while pos('","',s)<>0 do begin
	k:=pos('","',s);
	for i:=1 to k-1 do write(s[i]);
	writeln;
	delete(s,1,k+2);
    end;
    writeln(s);
    close(output);
end.

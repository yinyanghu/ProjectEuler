program change;
var ch:char;
begin
    assign(input,'words.txt'); reset(input);
    assign(output,'problem42.txt'); rewrite(output);
    read(ch);
    while not eof do begin
	read(ch);
	while ch in ['A'..'Z'] do begin
	    write(ch);
	    read(ch);
	end;
	writeln;
	read(ch); read(ch);
    end;
    close(input);
    close(output);
end.
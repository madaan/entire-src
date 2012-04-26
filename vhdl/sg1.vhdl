--sg
entity sg1 is end;
architecture sg1 of sg1 is 
begin
process
begin
report bit'image(('1' and '0') and '1');

wait;
end process;
end;


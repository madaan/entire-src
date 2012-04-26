--sg
entity fa is 
port(x,y,z:in bit;s,c:out bit);
end;
architecture fa of fa is
begin
s<= ( x xor y ) xor z;
c<= ( x and y ) or( z and y ) or ( x and z);
end;
use STD.TEXTIO.all;
entity tb is end;
architecture tb of tb is
component fa is 
port(x,y,z:in bit;s,c:out bit);
end component;
file a:text open read_mode is "testcase.txt";
file b:text open write_mode is "sgop.txt";
signal x1,y1,z1,s1,ca1:bit;
begin
f1:fa port map(x1,y1,z1,s1,ca1);
process
variable a1,b1,c1:bit;
variable i:integer;
variable l1:line;
variable l2:line;
begin
while not endfile(a) 
loop
readline(a,l1);
read(l1,a1);
read(l1,b1);
read(l1,c1);
write(l2,bit'image(a1) & "+" &bit'image(b1) & "+" &bit'image(c1)&"=");
x1<=a1;
y1<=b1;
z1<=c1;
wait for 90 ns;
write(l2,bit'(s1));
write(l2,string'("---"));
write(l2,bit'(ca1));
writeline(b,l2);
end loop;
wait;
end process;
end;

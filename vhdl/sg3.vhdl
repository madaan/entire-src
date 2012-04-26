--sg
package sgmp is
function to_int(a:bit_vector) return integer;

function to_vec17(a:integer)  return bit_vector ;
end sgmp;
package body sgmp is
function to_int(a:bit_vector) return integer is
variable temp:integer:=0;
begin
for i in a'range loop
if(a(i)='1') then
temp:=temp+(2**i);
report integer'image(temp);
end if;
end loop;
return temp;
end;

function to_vec17(a:integer)  return bit_vector is
variable res:bit_vector(16 downto 0);
variable temp:integer;
begin
temp:=a;
for i in 0 to 16 loop
if(temp>=(2**i)) then
res(i):='1';
temp:=temp-2**i;
report integer'image(temp);
end if;
end loop;
return res;
end;
end sgmp;
use WORK.sgmp.all;
use STD.TEXTIO.all;
entity tb1 is end;
architecture tb1 of tb1 is
file a:text open write_mode is "sgop.txt";
begin
process
variable temp:integer;
variable l1:line;
variable arg:bit_vector(16 downto 0):="00000000000000111";
variable argrev:bit_vector(16 downto 0);
begin
temp:=to_int(arg);
argrev:=to_vec17(temp);
write(l1,integer'(temp));
write(l1,bit_vector'(argrev));
writeline(a,l1);
wait;
end process;
end;


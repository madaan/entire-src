a = input('Type in the first sequence = ');
b = input('Type in the second sequence = ');
z1=input('ref1');
z2=input('ref2');
la=length(a);
lb=length(b);
start=-(z1+z2);
M=la+lb-1;
n = start:1:M+start-1;
res=zeros(5);
for i=1:la
    for j=1:lb
        res(i+j)=res(i+j)+a(i)*b(j);
    end
end
res1=res(2:M+1);
stem(n,res1)
xlabel('Time index n'); ylabel('Amplitude');
 a=1;
 b=1;
  c=0;
 x=zeros(1,62832);
for i=0:.01:200*pi
    
    x(a)=sin(20000*i)*exp(-i/444);
    
    a=a+1;
end
plot(x)
disp(x)
wavwrite(x,20,'~/wt.wav');
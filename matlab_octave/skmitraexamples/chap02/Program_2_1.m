% Program 2_1
% Generation of the ensemble average
%
R = 50;
m = 0:R-1;
s = 2*m.*(0.9.^m); % Generate the uncorrupted signal
d = rand(R,1)-0.5; % Generate the random noise
x1 = s+d';
subplot(4,2,1);
stem(m,s);

xlabel('Time index n');ylabel('Amplitude'); title('Original Signal');

for n = 1:6;
    d = rand(R,1)-0.5; %it is generating R random values

    x = s + d';
    x1 = x1 + x;
 
  subplot(4,2,n+1);
  stem(m,x);
end

x1 = x1/6;
subplot(4,2,8);
stem(m,x1);

xlabel('Time index n');ylabel('Amplitude'); title('Ensemble average');
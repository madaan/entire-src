% Program 11_8
% Simulation of IIR Cascaded Lattice Structure
%
k = input('Type in the lattice multiplier coefficients = ');
alpha = input('Type in the feed-forward multiplers = ');
x = [1 zeros(1,2*length(k))];
[f,g] = latcfilt(k,alpha,x);
% Verify the structure
[p,d] = strucver(f,length(k));
disp('Actual numerator coefficients are '); disp(p');
disp('Actual denominator coefficients are '); disp(d');
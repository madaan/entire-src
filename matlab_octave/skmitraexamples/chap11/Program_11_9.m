% Program 11_9
% Simulation of FIR Cascaded Lattice Structure
%
k = input('Type in the multiplier values = ');
x0 = [1 zeros(1,length(k))];
[f,g] = latcfilt(k,x0);
disp('Filter Coefficients');disp(f);
disp('Mirror Image Filter Coefficients');disp(g);
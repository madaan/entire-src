% Program 8_7
% FIR Cascaded Lattice Realization
%
format long
num = input('Transfer function coefficients = ');
k = tf2latc(num);
disp('Lattice coefficients are'); disp(fliplr(k'));
x = (0:0.01:1);
n = length(x);

#k = @(x, y) sin(x + y);
#k = @(x, y) min(x, y);
k = @(x, y) exp (-100 * (x - y) ^ 2);
#k = @(x, y) 1   
c = zeros(n, n);
for i = 1:n
    for j = 1:n
        c(i, j) = k(x(i), x(j));
    end
end


u = randn(n, 1);
[A, S, B] = svd(c);

z = A * sqrt(S) * u;


plot(x, z, '.')
axis([0, 1, -2, 2])


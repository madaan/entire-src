for t = linspace(0, 2 * pi, 250);
y = [cos(t) ^ 2; sin(t) ^ 2; cos(t) * sin(t)];
plot_hyp(y, 0)
hold on;
end


function[] = plot_hyp(W, b)
    [x, y] = meshgrid(-15:0.5:15); 
    Zv = @(x,y) (-W(1) * x -W(2) * y + b) / W(3);
    mesh(x,y,Zv(x,y));


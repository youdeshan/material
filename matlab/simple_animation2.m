Nt = 100;
xmin = 0.1;
xmax = 0.9;
yval = 0.3;
dt = 0.03;

x = linspace(xmin, xmax, Nt);
for it = 1 : Nt
    plot([x(1), x(it)], [yval, yval], 'r', ...
        x(it), yval, 'ro');
    axis([0, 1, 0, 1]);
    pause(dt);
    drawnow
end
Nt = 100;
R = 1.2;
T = 1;
dt = 0.06;

t = linspace(0, 1, Nt);
x = zeros(1, Nt);
y = zeros(1, Nt);

for it = 1 : Nt
    x(it) = R * cos(2 * pi * t(it) / T);
    y(it) = R * sin(2 * pi * t(it) / T);
end

for it = 1 : Nt
    %line([-R, R], [0, 0]);
    plot(x(1 : it), y(1 : it), 'r', ...
        x(it), y(it), 'ro', ...
        1.2 * [-R, R], [0, 0], 'k', ...
        [0, 0], 1.2 * [-R, R], 'k', ...
        [0, x(it)], [0, y(it)], 'k', ...
        [0, x(it)], [0, 0], 'b', ...
        [0, 0], [y(it), 0], 'b', ...
        [x(it), x(it)], [0, y(it)], ':b', ...
        [0, x(it)], [y(it), y(it)], ':b');
    axis(1.2 * [-1, 1, -1, 1]);
    axis square;
    pause(dt);
    drawnow
end
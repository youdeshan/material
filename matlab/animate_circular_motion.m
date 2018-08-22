Nt = 100;
R = 1.2;
T = 1;
dt = 0.03;

t = linspace(0, 1, Nt);
x = zeros(1, Nt);
y = zeros(1, Nt);

for it = 1 : Nt
    x(it) = R * cos(2 * pi * t(it) / T);
    y(it) = R * sin(2 * pi * t(it) / T);
end

for it = 1 : Nt
    plot(x(1 : it), y(1 : it), 'r', ...
        x(it), y(it), 'ro');
    axis(1.2 * [-1, 1, -1, 1]);
    axis square;
    pause(dt);
    drawnow
end
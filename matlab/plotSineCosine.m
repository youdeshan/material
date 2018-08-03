Nx = 300;
xmax = 3 * pi;

x = linspace(0, xmax, Nx);
y1 = sin(x);
y2 = cos(x);

plot(x, y1, 'r-.', ...
    x, y2, 'b--', ...
    [pi, pi], [-10, 10], 'g');
grid on;
xlabel('x');
ylabel('sin(x), cos(x)');
legend('sin(x)', 'cos(x)');
axis([0, xmax, -1, 1]);
xmin = 0;
xmax = 3;
Nx = 200;

x = linspace(xmin, xmax, Nx);
f = 3 * x.^2;

plot(x, f);
xlabel('x');
ylabel('f(x)=3x^2');
title('A simple plot');
grid on
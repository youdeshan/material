% demoSurf
% Author: Yuen D. Hertlocher
%% set parameters
Nx=50;
xmin=-2;
xmax=+2;
%% make grid
x=linspace(xmin, xmax, Nx);
y=linspace(xmin, xmax, Nx);
[X, Y]=meshgrid(x, y);
%% calculate function z=f(x, y)
Z = X.^2 .* exp(-X.^2 - Y.^2);
%% plot surface
surf(X, Y, Z);
xlabel('x');
ylabel('y');
zlabel('z');
xmin = 0;
xmax = 5;
nx = 100;
range = 10;

x = linspace(xmin, xmax, nx);
y1 = 2 * x - 10;
plot(x, y1);

y2 = (-3 * x + 1) / 2;
hold on
  plot(x, y2);
hold off

params = [2, -1; 3, 2];
b = [10; 1];
intersect = params \ b;
hold on 
  plot(intersect(1, :), intersect(2, :), 'ro');
  text(intersect(1, 1) + 1, intersect(2, 1) + 1, ['P(', num2str(intersect(1, 1)), ', ', num2str(intersect(2, 1)), ')']);
hold off

xlabel('X');
ylabel('Y');
legend('2x-y=10', '3x+2y=1'); 
axis([-range, range, -range, range]);
grid on;
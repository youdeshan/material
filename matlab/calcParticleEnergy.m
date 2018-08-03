clear

g = 9.81;
m = 0.01;
y = 6.0;
vy = 5.2;

Ekin = 0.5 * m * vy^2;
Epot = m * g * y;
Etot = Ekin + Epot;

disp('Calculation of particle energy');
disp('--------------------------------');
disp(['mass(kg)=', num2str(m)]);
disp(['height(m)=', num2str(y)]);
disp(['velocity(m/s)=', num2str(vy)]);
disp(' ');
disp(['Kinetic Energy(J)=', num2str(Ekin)]);
disp(['Potential Energy(J)=', num2str(Epot)]);
disp(['Total Energy(J)=', num2str(Etot)]);
disp(' ');

v1 = [1, 3, 4, 6, 5, 2];
v2 = [1, 2, 2, 3, 4, 2];
plot(v1, v2, 'r*--');
axis([0, 7, 0, 5]);

%x = 0: pi/100: 2 * pi;
%x = linspace(-2 * pi, 2 * pi);
%y1 = sin(x);
%y2 = sin(x - 0.25);
%y3 = sin(x - 0.5);
%Y = magic(4);

%figure
%plot(x, y1, x, y2);
%plot(Y)
%plot(x, y1, x, y2, '--', x, y3, ':');
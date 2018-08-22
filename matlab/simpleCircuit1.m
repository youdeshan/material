Vs = 6;
R1 = 1e3;
R2 = 2e3;

% A * u = b ==> u = A \ b
A = [1, 0, 0, 0, 0; ...
    0, 0, -1, 0, 1; ...
    0, 0, 1, -1, 0; ...
    1, -1, -R1, 0, 0; ...
    0, 1, 0, -R2, 0];
b = [Vs; 0; 0; 0; 0];
u = A \ b;

v1 = u(1);
v2 = u(2);
I1 = u(3);
I2 = u(4);
I3 = u(5);

clc;
disp(['==============================']);
disp(['Vs= ', num2str(Vs), ' volts']);
disp(['R1= ', num2str(R1), ' ohms']);
disp(['R2= ', num2str(R2), ' ohms']);
disp(['   Solution:']);
disp(['v1= ', num2str(v1), ' volts']);
disp(['v2= ', num2str(v2), ' volts']);
disp(['I1= ', num2str(I1), ' amps']);
disp(['I2= ', num2str(I2), ' amps']);
disp(['I3= ', num2str(I3), ' amps']);
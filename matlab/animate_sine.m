Nx=200;
Nt=200;
lambda=1; % spatial wavelength
T=1; % period
A=1; % amplitude
xmax=3*lambda ;
Tmax=4*T ;
tpause=0.02; % controls animation speed
k=2*pi/lambda ; % wavenumber
omega=2*pi/T ; % angular frequency

x=linspace(0, xmax, Nx);
t=linspace(0, Tmax, Nt);

for it=1:Nt
y=sin(k*x-omega*t(it));
plot(x,y);
xlabel('x')
ylabel('y')
title('Traveling wave')
pause(tpause)
drawnow
end
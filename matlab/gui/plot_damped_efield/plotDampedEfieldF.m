function plotDampedEfieldF(handles)
%% plotDampedEfield
% plot a damped sinusoidal electric field
% with skin depth a
% domain is 0 to 10 microns

%% set parameters
%a=3; % skin depth (microns)
a = get(handles.depthSlider, 'Value');
E0=12; % magnitude of field at x=0 (V/micron)
lambda=1; % period of oscillation (microns)
xmin=0;
xmax=10;
Nx=200;

%% initialize arrays
x=linspace(xmin, xmax, Nx);
E=zeros(1,Nx);
%% calculate field
k=2*pi/lambda;
E=E0*cos(k*x).*exp(-x/a);
%% plot results
hax = handles.plotAxes;
plot(hax, x, E);
axis(hax, [xmin, xmax, -E0, E0]);
xlabel(hax, 'x (microns)');
ylabel(hax, 'E(V/micron)');

show_grid = get(handles.gridCheckbox, 'Value');
if show_grid
  grid(hax, 'on');
else
  grid(hax, 'off');
end
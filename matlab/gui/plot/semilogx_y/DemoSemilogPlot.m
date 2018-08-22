% DemoSemilogPlot.m
% demonstrate semilog plot
% Author: Pafnuty Chebyshev
%% set parameters
tau=5; % characteristic time
alpha5=15;
Nt=50;
Tf=30*tau;
%% tabulate function
t=linspace(0, Tf, Nt);
T5=16*t.^5 -20*t.^3+5*t;
y=alpha5*T5.*exp(-t/tau);
%% plot function
semilogy(t/tau, y, 'o-') % semilogx
ylabel('$y$',...
'Interpreter', 'latex', 'FontSize', 14)
xlabel('$t/\tau$',...
'Interpreter', 'latex', 'FontSize', 14);
title('$y(t)=\alpha_5 (16t^5-20t^3+5t)e^{-t/\tau}$',...
'Interpreter', 'latex', 'FontSize',14)
grid on
set(gca, 'FontSize', 10)
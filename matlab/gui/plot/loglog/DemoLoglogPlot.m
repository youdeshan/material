% DemoLoglogPlot.m
% demonstrate loglog plot plot
% plotting the fifth Chebyshev polynomial
% Author: A. Lincoln
%% set parameters
Nt=30;
Tf=100;
%% tabulate function
t=linspace(1, Tf, Nt); % linear spacing
T5=16*t.^5 -20*t.^3+5*t;
tL=logspace(0, 2, Nt); % log spacing
T5L=100*(16*tL.^5 -20*tL.^3+5*tL);

%% plot function
loglog(t, T5, 'o-', tL, T5L, 's-')
hleg = legend('$T_5(t)$', '$100 T_5(t)$', 'Location', 'SouthEast')
set(hleg, 'Interpreter', 'latex');
ylabel('$y$',...
'Interpreter', 'latex', 'FontSize', 14)
xlabel('$t$',...
'Interpreter', 'latex', 'FontSize', 14);
title('$T_5(t)=16t^5-20t^3+5t$',...
'Interpreter', 'latex', 'FontSize', 14)
grid on
set(gca,'FontSize',10)
The
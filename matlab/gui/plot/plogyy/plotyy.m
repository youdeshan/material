%% plot function y(t) and vy(t)
% given vectors t, y, vy
[hax, hy, hvy]=plotyy(t/tau, y, t/tau, vy);
legend(hax(1), 'Position y', 'Velocity v_y')
% properties of time label on horizontal axis
xlabel(hax(1), 't/$\tau$',...
'Interpreter', 'latex', 'FontSize', 14);
% properties of y line, ticks, and label
set(hy, 'LineWidth', 1.5); % make line thick
set(hy, 'Color', 'k'); % make line black
set(hax(1), 'YTick', [-1:0.25:1], 'Ycolor', 'k');
ylabel(hax(1), 'y (m)', 'Color', 'k',...
'FontSize', 14, ...
'FontName', 'Times New Roman')
% properties of vy line, ticks, and label
set(hvy, 'LineStyle', '--');
set(hvy, 'LineWidth', 2); % make line thick
set(hvy, 'Color', 'b'); % make line blue
set(hax(2), 'YTick', [-2:0.5:2],...
'YColor', 'b');
ylabel(hax(2), 'v_y (m/s)', 'FontSize', 14,...
'FontName', 'Times New Roman')
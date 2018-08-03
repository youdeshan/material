temperatures = [71, 80, 73, 72, 78, 81, 73, 76];
sortedTemps = sort(temperatures);
Tmin = 65;
Tmax = 85;

bar(sortedTemps);
xlabel('Measurement');
ylabel('Temperature(F)');
grid on;
axis([0, length(temperatures) + 1, Tmin, Tmax]);
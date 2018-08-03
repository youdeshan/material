q0 = 1.5;
sigmaq = 0.25;
qmin = 0.0;
qmax = 2.5;

Nq = 200;
qa = linspace(qmin, qmax, Nq);

TicHeight = 0.3;

prefactor = 1 / sqrt(2 * pi * sigmaq ^ 2);
Gauss = prefactor * exp(-(qa - q0).^2 / (2 * sigmaq ^ 2));
fmax = max(Gauss);

plot(qa, Gauss);
xlabel('q');
ylabel('Normal distribution');
axis([qmin, qmax, 0, 1.2 * fmax]);
grid on;

qupper = q0 + sigmaq;
qlower = q0 - sigmaq;
fupper = prefactor * exp(-(qupper - q0).^2/(2 * sigmaq^2));
flower = prefactor * exp(-(qlower - q0).^2/(2 * sigmaq^2));
MarkLength = TicHeight * fmax;
line([qupper, qupper], ...
    [fupper - MarkLength / 2, fupper + MarkLength / 2], ...
    'Color', 'r');
line([qlower, qlower], ...
    [fupper - MarkLength / 2, fupper + MarkLength / 2], ...
    'Color', 'r');

text(q0 + 1.2 * sigmaq, fupper, '+\sigma', 'Color', 'r');
text(q0 - 1.6 * sigmaq, flower, '-\sigma', 'Color', 'r');

Ndata = 10000;
q0 = 1.5;
sigmaq = 0.25;
qmin = 0.0;
qmax = 2.5;
nbins = 25;

qdata = q0 + sigmaq * randn(1, Ndata);
[nq, qs] = hist(qdata, nbins);
bar(qs, nq);
disp(['qs=', num2str(length(qs))]);
disp(['nq=', num2str(length(nq))]);

xlabel('Value of q');
ylabel('Number of data points in bin');
axis([qmin, qmax, 0, inf]);

Nq = 200;
qa = linspace(qmin, qmax, Nq);

Pq = max(nq) * exp(-(qa-q0).^2/(2*sigmaq^2));
hold on
  plot(qa, Pq, 'r', 'LineWidth', 2);
hold off
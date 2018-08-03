Ndata = 10000;
q0 = 1.5;
sigmaq = 0.25;
qmin = 0.0;
qmax = 2.5;
nbins = 25;

qdata = q0 + sigmaq * randn(1, Ndata);
hist(qdata, nbins);

xlabel('Value of q');
ylabel('Number of data points in bin');
axis([qmin, qmax, 0, inf]);
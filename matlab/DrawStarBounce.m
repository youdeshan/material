Nb = 32;
dt = 0.005;
Nbounce = 4;

for (kbounce = 1 : Nbounce)
    for (kb = 1 : Nb)
        disp([blanks(kb), '*']);
        pause(dt);
    end
    for (kb = Nb : -1 : 1)
        disp([blanks(kb), '*']);
        pause(dt);
    end
end
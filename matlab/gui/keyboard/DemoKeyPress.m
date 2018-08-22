function DemoKeyPress
figure(1);
set(gcf, 'KeyPressFcn', @processKey);

function processKey(src, evnt)
if length(evnt.Character) >= 1
    clc;
    disp(['Character: ', evnt.Character]);
    disp(['Modifiers: ', ca2str(evnt.Modifier)]);
    disp(['Key:       ', evnt.Key]);
end

function cas = ca2str(ca)
[n1, n] = size(ca);
cas = ' ';
for k = 1 : n
    cas = [cas, ca{k}];
    if k ~= n
        cas = [cas, '-'];
    end
end
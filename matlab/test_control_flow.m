i_num = input('Enter number to check: ');
if (isprime(i_num))
    disp(['Yes! ', num2str(i_num), ' is prime!'])
else
    disp(['Yes! ', num2str(i_num), ' is not prime!'])
end

for (k = 1 : i_num)
    disp(['k = ', num2str(k)]);
end

%{
for s = [0 : 0.1 : 1]
    disp(s)
end
%}

%using this
s = linspace(0, 1, 11);
for is = 1 : length(s)
    disp(s(is));
end

disp('************Switch statement*************');
monthStr = 'February';
switch monthStr
    case 'February'
        nDays = 28;
    case {'September', 'April', 'June', 'November'}
        nDays = 30;
    otherwise
        nDays = 31;
end
disp([monthStr, ' has ', num2str(nDays), ' days in a year!']);
disp('************Switch statement*************');
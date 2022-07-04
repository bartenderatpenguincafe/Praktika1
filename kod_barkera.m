close all
I=[1 1 1 1 1 0 0 1 1 0 1 0 1 0]; %Сам код 
% 13 элементов [1 1 1 1 1 0 0 1 1 0 1 0 1 0] 'ноль в конце для красоты отображения'
% 11 элементов [1 1 1 0 0 0 1 0 0 1 0]
% 7 элементов [1 1 1 0 0 1 0]
% 5 элементов [1 1 1 0 1]
% 4 элемента [1 0 1 1] или [1 0 0 0]
% 3 элемента [1 1 0]
% 2 элемента [1 0] или [1 1]
Fs = 1e3;   % частота дискретизации ,Гц
T=1;        % длительность элемента,c

N = T*Fs;  %дискретизация элемента (указание на то сколько отсчетов будет в одном элементе)          
one = ones(1,N);    % массив едениц 
zero = zeros(1,N);  % массив нулей 

result = []; %пустой массив 
for i=1:length(I) %цикл заполнения 
    if (I(i)==0) %если удовлетворяет условию:
        t_d = zero; %N(кол-во соответсвует Fs*T) нулей на элемент 
    else 
        t_d = one;%N едениц на элемент 
    end
    result = [result t_d]; %запись в массив результата 
    %запись проихсодит так : в уже имеющийся массив добавляется новый
    %элемент с длиной N
end

x = 0 : 1/Fs : T*length(I) - 1/Fs; %градуировка  
plot (x,result);
ylim ([0 2]);%установил для того чтобы график красиво смотрелся на оси 
xlim ([0 (length(I)+1)]);
grid on


%-------------------------------------------------------------------------%
%-----------------------------Тестовая зон--------------------------------%
%-------------------------------------------------------------------------%
%Каждый элемент "удлинили" в Fs раз, а получившуюся последовательность
%повторили 10 раз
a_new = [I zeros(1,50)];
A  = repmat(a_new, Fs, 10);
A  = A(:)'; %превращение в колонну 
%Сформировали вектор временных отсчетов, значения которых нормированы
%относительно длительности всей последовательности
x1  = (0:length(A) - 1)/Fs;
%Сформировали несущую
s0 = square(x1);
%Промодулировали несущую кодом Баркера
s  = s0.*A;
figure  ;
plot(x1, s);
ylim ([-2 2]);
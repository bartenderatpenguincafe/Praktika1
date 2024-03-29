close all
clear

I=[1 1 1 1 1 -1 -1 1 1 -1 1 -1 1]; %Сам код 
% 13 элементов [1 1 1 1 1 -1 -1 1 1 -1 1 -1 1] 
% 11 элементов [1 1 1 -1 -1 -1 1 -1 -1 1 -1]
% 7 элементов [1 1 1 -1 -1 1 -1]
% 5 элементов [1 1 1 -1 1]
% 4 элемента [1 -1 1 1] или [1 -1 -1 -1]
% 3 элемента [1 1 -1]
% 2 элемента [1 -1] или [1 1]
fs = 1e7;   % частота дискретизации ,Гц
phi = 0;%default значение фазы;
tau = 10e-3;
T_per_s = 200e-4;
n_inmp = 10; %число повторений импульсов 
A = 1;
f_n = 0; % несущая частота - установлено специально для того чтобы показать что частота реально нулевая 
T_a = tau/(length(I));% длительность элемента, c
t=0:1/fs:T_a-1/fs;%градуировка 

%-------------------------------------------------------------------------%
%s_t = A*exp(1i*((2*pi*f_n.*t.^2./2*T_a) + phi)); общая формула имульса c нулевым сдвигом фазы 
%-------------------------------------------------------------------------%

%пустой массив для результатов 
s_t_B = [];
for i=1:length(I)
    if (I(i)==-1)
        phi = pi;
        t_d = A*exp(1i*((2*pi*f_n.*t.^2./2*T_a) + phi));
    else
        phi = 0; 
        t_d = A*exp(1i*((2*pi*f_n.*t.^2./2*T_a) + phi));
    end
    s_t_B = [s_t_B t_d];
end

t_t = 0:1:((length(s_t_B)-1));
figure
plot(t_t,s_t_B) %единичный импульс

s_t_n= [s_t_B zeros(1,round(fs*T_per_s)-length(s_t_B))];%массив с импульсом и нулями 

s_t_p= repmat(s_t_n,1,n_inmp); %уcтановка числа повторений 
figure;
t_new = 0:1:(length(s_t_p)-1);
plot(t_new,s_t_p);
grid on

%спектр 
Fft_S=abs(fft(s_t_p,fs));% Амплитуды преобразования Фурье сигнала
Fft_S=2*Fft_S./fs;% Нормировка спектра по амплитуде
F=0:1:fs/2-1/fs;% Массив частот вычисляемого спектра Фурье
figure;
plot(F,Fft_S(1:length(F)));% Построение спектра Фурье сигнала
grid on;











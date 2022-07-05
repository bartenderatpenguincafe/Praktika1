close all
A = 1; %амплитуда сигнала
f_s = 1e4;%частота дискретизации 
tau_imp = 1e-6;%длина импульса 
T_imp = 20e-6;%период импульса 
n_inmp = 10; %число повторений импульсов 
t=-tau_imp/2:1/f_s:tau_imp/2-1/f_s;%градуировка 
d_f = 10e6; % девиация частоты
f_n = 10e6; % несущая частота 
s_t = A*cos(2*pi*f_n.*t + 2*pi*d_f.*t.^2./(2*tau_imp));
%Применена изветсная формула W = wt + at^2/2*tau (с уточнением на то что 
%прменяем формулу на интерваое импульса )
figure; 
plot(s_t);
grid on
s_t_n= [s_t zeros(1,round(f_s*T_imp)-length(s_t))];
%добавление нулей в соответсвии с периодом и длинной импульса 
s_t_p= repmat(s_t_n,1,n_inmp); %учтановка числа повторений 
figure;
plot(s_t_p);
grid on



close all
%на данном этапе в виде наброска 
t = 0:0.01:50;
y = 1*rectpuls(t,10);
y_new = repmat(y,1,10);
figure
plot(y_new)
ylim([0 1])
grid on 
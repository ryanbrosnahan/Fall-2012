%HW set 2

%question 6
tic
x = -5:0.01:5;
y = (x+3) ./ ( (x.^2) + 5);
toc
figure(1)
plot(x,y)
title('question 6')
axis([-7 7 -.5 1])




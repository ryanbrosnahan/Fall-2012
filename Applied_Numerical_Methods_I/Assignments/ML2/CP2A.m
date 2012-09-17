%computing assignment 2A

w = 0.03;
M = 1;
L = 1.2;
N = 10;
EA = -0.3;
EB = -0.29;
x = (M+L)/2; 

for n=1:2400
    lambda = (n*pi)/(w+N);
    num = exp(lambda*(x-(2*L)))+exp(-lambda*x);
    num = num*sin(lambda*N)^2;
    den = exp(lambda*(M-(2*L)))+exp(-lambda*M);
    den = den*lambda^2;
    frac = num/den;
    fprintf('%d %e %e %e\n',n,num,den,frac)
end
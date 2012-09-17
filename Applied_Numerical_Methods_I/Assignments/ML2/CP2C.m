%computing assignment 2C

w = 0.03;
M = 1;
L = 1.2;
N = 10;
EA = -0.3;
EB = -0.1;
x = 1; 

for Nmax=100000:1000:150000
    sum = 0;
    for n=1:Nmax
        lambda = (n*pi)/(w+N);
        num = exp(lambda*(x+M-(2*L)))+exp(-lambda*(x-M));
        num = num*sin(lambda*N)^2;
        den = exp(lambda*((2*M)-(2*L)))+1;
        den = den*lambda^2;
        sum = sum + num/den;
    end
    E = 2*(EB-EA)*sum/w/(w+N) + (w*EB+N*EA)/(w+N);
    fprintf('%d %20.14e\n',Nmax,E)
end
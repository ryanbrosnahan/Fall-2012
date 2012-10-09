%backsub.m

function x = backsub(U, Y)
%Y=UX U:NxN Y:Nx1

N = length(Y);
x = zeros(N,1);
x(N) = Y(N)/U(N,N);

for k=N-1:-1:1
    x(k) = (Y(k)-U(k,k+1:N)*x(k+1:N))/U(k,k);
end

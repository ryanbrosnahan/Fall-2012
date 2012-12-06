function I = cSimpson(f, a, b, n)
%source http://www.pcs.cnu.edu/~bbradie/matlab/quadrature/simp.m
%composite Simpson's rule
h = (b - a)/n;
x = linspace ( a, b, n+1 );
for i = 1:n+1
    fx(i) = feval ( f, x(i) );
end

w = [ 1 zeros(1,n-1) 1 ];
w(2:2:n) = 4*ones(1,n/2);
w(3:2:n-1) = 2*ones(1,n/2-1);

I = (h/3) * sum ( w .* fx );

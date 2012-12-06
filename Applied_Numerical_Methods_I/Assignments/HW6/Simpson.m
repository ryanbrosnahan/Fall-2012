function I = Simpson(f, a, b)
%Simpson's quadrature integration of function f on [a, b]
h = (b - a)/2;
I = h/3 * (f(a) + 4 * f( (a+b)/2 ) + f(b));

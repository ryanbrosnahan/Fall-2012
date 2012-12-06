function I = trapezoid(f, a, b)
%trapezoid quadrature integration of function f on [a, b]
I = (b - a)/2 * (f(a) + f(b));

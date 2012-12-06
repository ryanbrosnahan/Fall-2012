function I = cTrapezoid(f, a, b, n)
h = (b - a)/n;
I = 0;
for k=0:n-1
    I = I + trapezoid(f, a + k*h, a + k*h + h);
end

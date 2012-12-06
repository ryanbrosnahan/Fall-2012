function I = gauss3(f, c, d)

a = -1; 
b = 1;

x = [-sqrt(3/5) 0 sqrt(3/5)];
w = [5/9 8/9 5/9];
n = length(x);
t = c + (d-c)/(b-a) * (x-a);

I = 0;
for k=1:n
    I = I + w(k)*f(t(k));
end
I = I * (d-c)/(b-a);
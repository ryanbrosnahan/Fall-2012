h = .001;
x = 0:h:2;
N = length(x);
AL(1) = 0;
AM(1) = 1;
AR(1) = 0;

for i=2:N-1
	AL(i) = ((h^-2) - (3/(2*h)));
	AM(i) = ((x(i)^2) - (2/(h^2)));
	AR(i) = ((h^-2) + (3/(2*h)));
end

AL(N) = 0;
AM(N) = 1;
AR(N) = 0;

r(1) = 10;
r(N) = -3;

for i=2:N-1
	r(i) = exp(-x(i));
end


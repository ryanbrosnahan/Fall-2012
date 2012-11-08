function y = horner(a, x)

	n = length(a) - 1;
	y = a(n+1);

	for k=n:-1:1
		y = a(k) + x * y;
	end

	
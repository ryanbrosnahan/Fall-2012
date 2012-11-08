function y = newtval(c, x, r)
    m = length(c);
    y = c(m);
    for k=m-1:-1:1
        y = c(k) + (r-x(k))*y;
    end
    
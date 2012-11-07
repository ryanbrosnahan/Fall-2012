function c = divdiff(x, y)
    m = length(x);
    D = zeros(m, m);
    D(:,1)=y;
    for j=2:m
        for k=j:m
            D(k, j) = (D(k,j-1) - D(k-1, j-1))/(x(k)-x(k-j+1));
        end
    end
    c = diag(D);
    
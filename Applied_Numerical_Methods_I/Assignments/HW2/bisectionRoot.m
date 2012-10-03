%bisectionRoot.m

function [a, b, c] = bisectionRoot(f, a, b, tol)
%f = function; a = left guess; b = right guess; tol = precision

ya = f(a);
yb = f(b);

if (ya * yb > 0) 
    disp('bad interval')
    return;
end


maxI = 1 + round( log2((b-a)/tol ) );

for k=1:maxI
    c = (a+b)/2;
    yc = f(c);
    
    if (yc == 0)
        a = c; b = c;
    elseif (yc * yb > 0)
        b = c; yb = yc;
    else
        a = c; ya = yc;
    end
    
    if (b-a < tol)
        break
    end
    
end
c = (a+b)/2;
        
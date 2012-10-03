%fixedPointRoot.m

function y = fixedPointRoot(g, p0,tol, maxI)
% g = function; p0 = guess; tol = precision; maxI = mapimum number of iterations

for k=1:maxI
    p = g(p0);
    abserr = abs(p-p0);
    relerr = abserr/(abs(p)+eps);
    
    if (abserr<tol) && (relerr<tol)
        break
    end
    p0 = p;
end

if (k == maxI)
    disp('failed to converge')
end

y = p;


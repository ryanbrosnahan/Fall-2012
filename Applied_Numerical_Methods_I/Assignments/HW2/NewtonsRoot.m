%NewtonsRoot.m

function [x, k] = NewtonsRoot(f, fp, x0, tol, maxI)
%f = function; fp = fdx; x0 = guess; tol = precision; maxI = maximum
%iterations

for k=1:maxI
    x = x0 - f(x0)/fp(x0);
    abserr = abs(x-x0);
    relerr = abserr / (abs(x) + eps);
    if (abserr<tol) && (relerr<tol)
        break
    end
    x0 = x;
end


%SecantRoott.m

function [x, k] = SecantRoot(f, x0, x1, tol, maxI)
%f = function; f = fdx; x0 = guess; tol = precision; maxI = maximum
%iterations

for k=1:maxI
    x = x1 - ( f(x1) * (x1 - x0) / (f(x1) - f(x0)) );
    
    abserr = abs(x-x0);
    relerr = abserr / (abs(x) + eps);
    if (abserr<tol) && (relerr<tol)
        break
    end
    x1 = x0;
    x0 = x;
end
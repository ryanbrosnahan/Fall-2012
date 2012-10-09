%jacobi.m

function [X,k] = jacobi(A,B,P,delta,max1)
N = length(B);
for k=1:max1
   for j=1:N
      X(j)=(B(j)-A(j,[1:j-1,j+1:N])*P([1:j-1,j+1:N]))/A(j,j);
   end
   err = norm(X'-P);
   relerr = err/(norm(X)+eps);
   P = X';
   fprintf('%4g  %20.15f  %20.15f  %20.15f\n',k,X(1),X(2),X(3))
   if (err<delta)|(relerr<delta)
      break
   end
end
X = X';
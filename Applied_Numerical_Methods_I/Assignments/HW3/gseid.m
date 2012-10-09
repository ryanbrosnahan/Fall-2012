%gseid.m

function [X,k]=gseid(A,B,P,delta,max1)
N=length(B);
X=zeros(N,1);
for k=1:max1
   for j=1:N
      X(j) = (B(j)-A(j,1:j-1)*X(1:j-1) - A(j,j+1:N)*P(j+1:N))/A(j,j);
   end
   err = abs(norm(X-P));
   relerr = err/(norm(X)+eps);
   P = X;
   fprintf('%4g  %20.15f %20.15f  %20.15f\n',k,X(1),X(2),X(3))
   if (err<delta)|(relerr<delta)
      break
   end
end
X = X';
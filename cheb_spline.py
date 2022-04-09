import numpy as np
import matplotlib.pyplot as plt
import random as rand
from scipy.interpolate import interp1d

def f(x):
    return np.sin(x)

def CreateX(a, b, n):
    X=np.array([])
    h=(b-a)/n
    for i in range(n+1):
        X=np.append(X, a+i*h)
    return(X)
def CreateH(X, n):
    H=np.array([])
    for i in range(n):
        H=np.append(H, X[i+1]-X[i])
    return H

def CreateSpline(x, y, c0, cN, H,N, a, b):
    A=np.zeros((N-1, N-1))
    B=np.array([])
    C=np.array([])
    A[0][0]=2*(H[0]+H[1])/6
    A[0][1]=H[1]/6
    for i in range(1, N-2):
        A[i][i-1]=H[i-1]/6
        A[i][i]=2*(H[i-1]+H[i])/6
        A[i][i+1]=H[i]/6
    A[N-2][N-3]=H[N-2]/6
    A[N-2][N-2]=2*(H[N-2]+H[N-1])/6
    for i in range(1, N):
        B=np.append(B, ((y[i+1]-y[i])/H[i])-((y[i]-y[i-1])/H[i-1]) )
    C=np.append(C, c0)
    C=np.append(C, np.linalg.solve(A,B))
    C=np.append(C, cN)
    return(C)

def Spline(t, X, fX, C, N):
    for i in range(N+1):
        if t==X[i]:
            return(fX[i])
    i=0
    if t>=X[0]:
        while not(t>X[i] and t<X[i+1]):
            i+=1
        h=X[i+1]-X[i]
        return fX[i]*(X[i+1]-t)/h + fX[i+1]*(t - X[i])/h + C[i]*((X[i+1] - t)**3 - h*h*(X[i+1] - t))/(6*h) + C[i+1]*((t-X[i])**3 - h*h*(t-X[i]))/(6*h)

def cheb(a, b, N):
     xcheb=[]
     xcheb.append(b)
     for i in range(N-1):
         xcheb.append((1/2)*((b-a)*np.cos(((2*i+1)*np.pi)/(2*(N)+2))+a+b))
     xcheb.append(a)
     xcheb.reverse()
     return (xcheb)

N=7
a=-5
b=5
c0=-np.sin(a)
cN=-np.sin(b)
#равномерное распределение
X=CreateX(a, b, N)
fX=f(X)
H=CreateH(X, N)
C=CreateSpline(X, fX, c0, cN, H, N, a , b)
xnew=np.linspace(a, b, 50)
fnew=f(xnew)
f1=interp1d(X, fX, kind=3)
S=[Spline(i, X, fX, C, N) for i in xnew]
Spline1=f1(xnew)
R=[abs(S[i]-Spline1[i]) for i in range(len(xnew))]
#распределение Чебышева
Xcheb=cheb(a, b, N)
print(Xcheb)
fCheb=f(Xcheb)
Hcheb=CreateH(Xcheb, N)
Ccheb=CreateSpline(Xcheb, fCheb, c0, cN, Hcheb, N, a , b)
Scheb=[Spline(i, Xcheb, fCheb, Ccheb, N) for i in xnew]
R=[abs(fnew[i]-Scheb[i]) for i in range(len(xnew))]




plt.figure(1)
plt.grid()
plt.xlabel('x', fontsize = 14)
plt.ylabel('y', fontsize = 14)
plt.plot(xnew,S, color='red', label=r'$S_{n}(x)$')
plt.plot(xnew,f(xnew), color='blue', label=r'$f(x)$')
plt.scatter(X,fX, color = 'blue', s=20, label = 'Узлы')
plt.legend()
plt.scatter(X,fX, color = 'black', s=20)
plt.title(r"Кубический сплайн, $S''(a)=0, S''(b)=0$")


plt.figure(2)
plt.grid()
plt.xlabel('x', fontsize = 14)
plt.ylabel('y', fontsize = 14)
plt.plot(xnew,Scheb, color='red', label=r'$S_{n}(x)$')
plt.plot(xnew,f(xnew), color='blue', label=r'$f(x)$')
plt.scatter(Xcheb,fCheb, color = 'blue', s=20, label = 'Узлы')
plt.legend()
plt.scatter(Xcheb,fCheb, color = 'black', s=20)
plt.title(r"Кубический сплайн чебышев, $S''(a)=0, S''(b)=0$")

plt.figure(3)
plt.grid()
plt.xlabel('x', fontsize = 14)
plt.ylabel('y', fontsize = 14)
plt.plot(xnew,R, color='red', label=r'$R_{n}(x)$')
plt.legend()
plt.title(r"Ошибка, $S''(a)=0, S''(b)=0$")
plt.show()

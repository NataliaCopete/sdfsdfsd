#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

int tiempo=3000;
double a=1/(2*sqrt(2.0));
double eps= 1e-3;
double h=0.006;
int Npuntos=tiempo/h;


double f(double q7, double p7){
return -(2*q7)/(pow(4*q7*q7+ eps*eps,3/2)) ;

}

double g(double q8, double p8)
{
 return p8; 

}

double w(double q1,double q2,double p2){

 return ((q1-q2)/pow((pow(q1-q2,2)+eps*eps/4),3/2))-((q1+q2)/pow((pow(q1+q2,2)+eps*eps/4),3/2));

}



int main(){

double q1;
double p1;
double q2;
double p2;



double kq11;
double kq12;
double kq13;
double kq14;
double kp11;
double kp12;
double kp13;
double kp14;
double *vect;
double *vect1;
double *vect2;
double *vect3;
 double *vect4;
double t1=0;
double kq21;
double kq22;
double kq23;
double kq24;
double kp21;
double kp22;
double kp23;
double kp24;



q1=a;
p1=0;
q2=-a;
p2=0;
/*vect q1*/
/*vect1 p1*/
/*vect2 t1*/
/*vect3 q2*/
/*vect4 p2*/

vect= new double[Npuntos];     
vect1=new double[Npuntos];    
vect2=new double[Npuntos];  
vect3=new double[Npuntos];
vect4=new double[Npuntos];

int cont=0;
while(t1<tiempo){



kp11= f(q1,p1);
kq11=g(q1,p1);
kp21= w(q1,q2,p2);
kq21=g(q2,p2);

kp12= f(q1+kq11*h/2,p1+kp11*h/2);
kq12= g(q1+kq11*h/2,p1+kp11*h/2);

kp22= w(q1,q2+kq21*h/2,p2+kp21*h/2);
kq22= g(q2+kq21*h/2,p1+kp21*h/2);

kp13= f(q1+kq12*h/2,p1+kp12*h/2);
kq13= g(q1+kq12*h/2,p1+kp12*h/2);
kp23= w(q1,q2+kq22*h/2,p2+kp22*h/2);
kq23= g(q2+kq22*h/2,p2+kp22*h/2);

kp14= f(q1+kq13*h,p1+kp13*h);
kq14= g(q1+kq13*h,p1+kp13*h);
kp24= f(q1,q2+kq23*h,p2+kp23*h);
kq24= g(q2+kq23*h,p2+kp23*h);

vect[cont]=q1;
vect1[cont]=p1;
vect2[cont]=t1;
vect3[cont]=q2;
vect4[cont]=p2;
q1=q1+h*1.0/6.0*(kq11+2*kq12+2*kq13+kq14);
p1=p1+h*1.0/6.0*(kp11+2*kp12+2*kp13+kp14);
q2=q2+h*1.0/6.0*(kq21+2*kq22+2*kq23+kq24);
p1=p1+h*1.0/6.0*(kp21+2*kp22+2*kp23+kp24);

t1=t1+h;

cont=cont+1;


}

for (int i=0;i<Npuntos;i++){
if(vect[i]*vect[i+1]<0){
cout<<vect3[i]<<" "<<vect4[i]<<endl;

}
 }

return 0;
}

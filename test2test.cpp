// Example program
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include<stdlib.h>
#include<math.h>
#define PI_nb 3.14159
//#include <stdlib>

std::vector<double> Simul_Brownien(int nb,double mu, double sigma)
{
    /// Simulation d'un brownien par les incréments gaussiens indépendants
    std::vector<double> n (nb);
    std::vector<double> W (nb);
    //double x1(0);
    //double x2(0);

    /// Simulation d'un échantillon 1D normale centré réduit par box Muller
    std::vector<double>::iterator it = n.begin();
    //for(i=0;i<nb;i++)
    for(;it != n.end();++it)
    {
        double x1 = rand()/(RAND_MAX + 1.0);
        double x2 = rand()/(RAND_MAX + 1.0);
        *it = sqrt(-2*log(x1))*cos(2*PI_nb*x2);
        *it = sigma*(*it) + mu;
        //std::cout << n[i] << std::endl;
    }
    W[0]=0;
   // std::cout << W[0] << std::endl;
    it = W.begin();
    for(int i(1);i<nb;i++)
    //for(; it != W.end();++it)
    {
        W[i] = W[i-1] + sqrt((1.0+0.0)/(nb+1.1-1.1))*n[i-1];
        //std::cout << W[i] << std::endl;
    }
    return W;
}
std::vector<double> Proc_O_U_Simul(int nb, double r0, double moyenne, double diffusion, double speed_retour)
{
    /// Simulation d'un processus Orstein-Uhlenbeck
    /// Bon pour observer le retour à la moyenne, faire du monte-carlo sur les taux
    std::vector<double> r (nb);
    std::vector<double> B = Simul_Brownien(nb,0,1);
    r[0]= r0;
    std::cout << r[0] << std::endl;
    for(int i(1);i<nb;i++)
      {
       r[i] = r[i-1] - speed_retour * (r[i-1]-moyenne)*(1.0/(nb+0.0)) + diffusion* (B[i]-B[i-1]);
       std::cout << r[i] << std::endl;
      }
    return r;
}
std::vector<double> Callable_bond_annuelle(const std::vector<double> & strike, const std::vector<double> & trajectoire)
{

    return res;
}

int main()
{
    int nb = 2520;// 10 ans
    double r0 = 0.5;
    double moyenne = 0.7;
    double diffusion = 0.2;
    double speed_retour = 1;

    std::vector<double> n = Proc_O_U_Simul(nb,r0,moyenne,diffusion,speed_retour);


}

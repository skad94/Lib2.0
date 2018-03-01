#include<iostream>
#include<math.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include "Blacky.h"
#include "VectorWrapper.h"
#include "VectorWrapper.cpp"
#include "Heston.cpp"
//#include "Heston.h"
#define PI_nb 3.14159
//std::vector<double> Simul_BrownienVolSto(double S0, double r,double rho, double Vvol, int nb);
std::vector<double> Simul_BrownienVolSto(double S0, double r,double rho, double Vvol, int nb,int nb_vol, double origine_vol, double moyenne, double speed_retour);

std::vector<double> Simul_Brownien(int nb,double mu, double sigma);

/*std::vector<double> Simul_BrownienVolSto(double S0, double r,double rho, double Vvol, int nb,int nb_vol, double origine_vol, double moyenne, double speed_retour)
//std::vector<double> Simul_GeomBrownien(cStock S,int nb)
{
    /// Simulation d'une trajectoire de l'EDS de B&S (loi log normale)
    /// Schéma d'Euler pour la discrétisation du schéma et les browniens sont obtenus avec box-mller et incréments gaussiens
    double dt = 1.0/(nb+0.0);
    std::vector<double> S (nb);/// Stock a vol sto
    std::vector<double> B1 = Simul_Brownien(nb,0,1);
    std::vector<double> B2 = Simul_Brownien(nb,0,1);
    S[0]= S0;
    std::vector<double> V = rho*B1 + sqrt(1-pow(rho,2))*B2; /// diffusion de vol
    for(int i(1);i<nb;++i)
    {
       S[i] = S[i-1] + S[i-1]* (r*dt + Vvol * V[i]*(B1[i]-B1[i-1]));
       std::cout << S[i] << std::endl;
    }
    return S;
}
*/
std::vector<double> Simul_Brownien(int nb,double mu, double sigma)
{
    /// Simulation d'un brownien par les incréments gaussiens indépendants
    std::vector<double> n (nb);
    std::vector<double> W (nb);

    /// Simulation d'un échantillon 1D normale centré réduit par box Muller
    std::vector<double>::iterator it = n.begin();
    //for(i=0;i<nb;i++)
    for(;it != n.end();++it)
    {
        double x1 = rand()/(RAND_MAX + 1.0);
        double x2 = rand()/(RAND_MAX + 1.0);
        *it = sqrt(-2*log(x1))*cos(2*PI_nb*x2);
        *it = sigma*(*it) + mu;
    }
    W[0]=0;
    it = W.begin();
    for(int i(1);i<nb;i++)
    //for(; it != W.end();++it)
    {
        W[i] = W[i-1] + sqrt((1.0+0.0)/(nb+1.1-1.1))*n[i-1];
    }
    return W;
}
int main()
{
    srand (time(NULL));
    /*int nb(50);
    double mu(1.0);
    double sigma(0.0);
    double res = Blacky_MC(100,1.0/100.0,20.0/100.0,1,250,1,0,50)*/
    double S0(100),r(0.02),vol(0.0),rho(0.6),Vvol(0.015);
    int nb = 1000;
    //std::vector<double> bronien;
    std::vector<double> s =  Simul_BrownienVolSto(S0,r,vol,rho,Vvol,nb);
    double res = 10;
    std::cout << " res = " << res <<  std::endl;
    return 0;
}

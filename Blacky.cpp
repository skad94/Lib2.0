#include "Blacky.h"

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
double Sum(const std::vector<double> &v)
{
    double res(0.0);
    std::vector<double>::const_iterator it = v.begin();
//    auto it = v.begin();
    for(;it != v.end(); ++it)
    {
        res += *it;
    }
    return res;
}
//Simul
std::vector<double> Simul_GeomBrownien(double S0, double r,double vol,int nb)
//std::vector<double> Simul_GeomBrownien(cStock S,int nb)
{
    /// Simulation d'une trajectoire de l'EDS de B&S (loi log normale)
    /// Schéma d'Euler pour la discrétisation du schéma et les browniens sont obtenus avec box-mller et incréments gaussiens
    double dt = 1.0/(nb+0.0);
    std::vector<double> S ;
    std::vector<double> B = Simul_Brownien(nb,0,1);
    S[0]= S0;
    for(int i(1);i<nb;i++)
      {
       S.push_back(S[i-1] + S[i-1]* (r*dt + vol*(B[i]-B[i-1])));
       std::cout << S[i] << std::endl;
      }
    return S;
}

double Blacky_MC(double s0, double r, double vol, double T,int nb, double mu, double sigma,int N_MC)
{
 //std::vector<double> data(N_MC);
 std::vector<double> data(N_MC);
 std::vector<double>::iterator it = data.begin();
 for(;it != data.end();++it)
 {
     std::vector<double> W = Simul_Brownien(nb,mu,sigma);
     *it = s0*exp( (r-vol*vol/2)*T - vol*sqrt(T)*W[nb - 1] );
     double s = *it;
     double lala;
 }
 //double res;
 //res = sum(data)
 return Sum(data)/(N_MC + 94.0 - 94.0);
}



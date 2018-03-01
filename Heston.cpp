#include "Blacky.h"
#include "VectorWrapper.h"
std::vector<double> Simul_Brownien(int ,double , double);
std::vector<double> Proc_CIR_Simulpart_deux(int nb, double origine, double moyenne, double diffusion, double speed_retour,std::vector<double> Bronien);
std::vector<double> Simul_BrownienVolSto(double S0, double r,double rho, double Vvol, int nb,int nb_vol, double origine_vol, double moyenne, double speed_retour);

/*std::vector<double> Simul_Brownien(int nb,double mu, double sigma)
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
*/

std::vector<double> Proc_CIR_Simul(int nb, double origine, double moyenne, double diffusion, double speed_retour)
{   /// Simulation d'un processus CIR
    /// Bon pour observer le retour la positivité des taux ssi sigma^2<2*k*theta, n'hésite pas a faire du monte-carlo en moyennant les sorties de ce truc
    /// on récupère en sortie une trajectoire de CIR
    std::vector<double> B (nb);
    std::vector<double> V (nb);
    int i;
    B = Simul_Brownien(nb,0,1);
    V[0]= origine;
    std::cout << V[0] << std::endl;
    for(i=1;i<nb;i++)
    {
       V[i] = V[i-1] - speed_retour * (V[i-1]-moyenne)*(1.0/(nb+0.0)) + diffusion * sqrt(V[i])*(B[i]-B[i-1]);
       std::cout << V[i] << std::endl;
    }
    return V;
}
std::vector<double> Proc_CIR_Simulpart_deux(int nb, double origine_vol, double moyenne, double diffusion, double speed_retour,std::vector<double> Bronien)
{   /// Simulation d'un processus CIR
    /// Bon pour observer le retour la positivité des taux ssi sigma^2<2*k*theta, n'hésite pas a faire du monte-carlo en moyennant les sorties de ce truc
    /// on récupère en sortie une trajectoire de CIR
    //std::vector<double> B (nb);
    std::vector<double> V (nb);
    V[0] = origine_vol;
    std::cout << V[0] << std::endl;
    for(int i(1);i<nb;i++)
    {
       V[i] = V[i-1] - speed_retour * ( V[i-1] - moyenne )*(1.0/(nb+0.0)) + diffusion * sqrt(V[i])*(Bronien[i]-Bronien[i-1]);
       std::cout << V[i] << std::endl;
    }
    return V;
}

std::vector<double> Simul_BrownienVolSto(double S0, double r,double rho, double Vvol, int nb,int nb_vol, double origine_vol, double moyenne, double speed_retour)
//std::vector<double> Simul_GeomBrownien(cStock S,int nb)
{
    /// Simulation d'une trajectoire de l'EDS de B&S (loi log normale)
    /// Schéma d'Euler pour la discrétisation du schéma et les browniens sont obtenus avec box-muller et incréments gaussiens
    double dt = 1.0/(nb+0.0);
    std::vector<double> S (nb);/// Stock a vol sto
    std::vector<double> B1 = Simul_Brownien(nb,0,1);
    std::vector<double> B2 = Simul_Brownien(nb,0,1);
    S[0]= S0;
    std::vector<double> B = rho*B1 + sqrt(1-pow(rho,2))*B2; /// diffusion de vol
    std::vector<double> V = Proc_CIR_Simulpart_deux(nb,origine_vol,moyenne,Vvol,speed_retour,B);
    for(int i(1);i<nb;++i)
    {
       S[i] = S[i-1] + S[i-1]* (r*dt + V[i]*(B1[i]-B1[i-1]));
       std::cout << S[i] << std::endl;
    }
    return S;
}


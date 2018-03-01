#ifndef Blacky.h

#include<iostream>
#include<math.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#define PI_nb 3.14159


std::vector<double> Simul_Brownien(int nb,double mu, double sigma);
double Blacky_MC(double s0, double r, double vol, double T,int nb, double mu, double sigma,int N_MC);
double Sum(const std::vector<double> &v);
std::vector<double> Simul_Brownien(int nb,double mu, double sigma);

std::vector<double> Simul_BrownienVolSto(double S0, double r,double vol,double rho,double Vvol, int nb);
std::vector<double> Proc_CIR_Simul(int nb, double origine, double moyenne, double diffusion, double speed_retour);

#endif // Simulations_VA

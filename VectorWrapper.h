#ifndef VECTORWRAPPER_H_INCLUDED
#define VECTORWRAPPER_H_INCLUDED

#include<math.h>
#include<vector>
#include<time.h>
#include<stdlib.h>

void affiche(const std::vector<double> &v,int horizontale = 0);
std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs);
std::vector<double> ScalaireFoisVector(double x, const std::vector<double>& lhs);

#endif // VECTORWRAPPER_H_INCLUDED

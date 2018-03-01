#include<math.h>
#include<vector>
#include<iostream>
#include<time.h>
#include<stdlib.h>

void affiche(const std::vector<double> &v,int horizontale)
// void SKVector::affiche()
{
     ///   horizontale est à 0 par défaut pour un affichage VERTICALE mettre a 1 pour un affichage horizontale
      if(horizontale == 0)
      {
         //auto it = v.vect.begin();
        for(int i=0;i<v.size();i++)
    {
        std::cout << v[i] << std::endl;
    }
      }
      else
      {
          //auto it = v.vect.begin();
        for(int i=0;i<v.size();i++)
        {
        std::cout << v[i] << " ; ";// << std::endl;
        }
      }
}



std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs)
{
    if(lhs.size() != rhs.size())
    {	// meme tailles??
		std::cout << " Tailles pas bonnes" << std::endl;
    }
	std::vector<double> res(lhs.size());
	for(int i=0; i < lhs.size(); i++)
    {
		res[i] = lhs[i] + rhs[i];
	}
	return res;
}
std::vector<double> operator+(const double a, const std::vector<double>& rhs)
{
    std::vector<double> resa (rhs.size(),a);
    return resa + rhs;
}
std::vector<double> operator*(const double a, const std::vector<double>& rhs)
{
    std::vector<double> res(rhs.size());
    for(int i(0);i<res.size();++i)
    {
        res[i] = a*rhs[i];
    }
    return res;
}
std::vector<double> operator*(const std::vector<double>& lhs, const std::vector<double>& rhs)
{
    std::vector<double> res(rhs.size());
    for(int i(0);i<res.size();++i)
    {
        res[i] = rhs[i]*lhs[i];
    }
    return res;
}
std::vector<double> ScalaireFoisVector(double x, const std::vector<double>& lhs)
{
    std::vector<double> res;
    for(int i(0);i<res.size();++i)
    {
        res.push_back(x*lhs[i]);
    }
    return res;
}

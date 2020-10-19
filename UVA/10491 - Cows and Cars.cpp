#include<bits/stdc++.h>
using namespace std;

int main()
{
     double nCows,nCars,nShow;

     while(cin>>nCows>>nCars>>nShow)
     {
          //In the first case, the chance of picking a cow first + the chance of switching to a car
          //here -1 for the door already chosen
          double prob1 = (nCows)/(nCows+nCars) * (nCars)/(nCows+nCars-nShow-1);

          //In the second case, the chance of picking a car first + the chance of switching to a car
          double prob2 = (nCars)/(nCows+nCars) * (nCars-1)/(nCows+nCars-nShow-1);

          printf("%.5lf\n",prob1+prob2);
     }
}

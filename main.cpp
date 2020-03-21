#include <iostream>
#include "Alligator.h"
#include "Doggo.h"
#include "HouseCat.h"



using namespace std;
int main() {
    Alligator alligator1 = Alligator(50,500,"Timmy",false);
    Doggo dog1 = Doggo(12,50,"Rex",false);
    HouseCat cat1 = HouseCat(10,9,"Reginald",false);
    cat1.animalCall();
    for(int i = 0; i < 5; ++i){
        cat1.feedAnimal();
    }
    cout << cat1.getWeight() << endl;
    cout << cat1.calculateHappiness() << endl;
    cout << dog1.calculateHappiness() << endl;
    return 0;
}
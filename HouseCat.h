//
// Created by xenon on 3/21/2020.
//

#ifndef AC_PROJECT5_HOUSECAT_H
#define AC_PROJECT5_HOUSECAT_H

#include "Animal.h"

class HouseCat : public Animal{
public:
    //contstructors
    HouseCat(int age, float weight, string name, bool albino){
        setTimesFed(0);
        setAge(age);
        setWeight(weight);
        setName(name);
        setAlbino(albino);
    }
    //virtual methods
    void animalCall() override {
        cout << "Meow" << endl;
    }
    void feedAnimal() override {
        setTimesFed(timesFed+1);
        redoAnimalWeight();
    }
    void redoAnimalWeight() override {
        if(timesFed >= 3){
            weight = weight*1.25;
            timesFed = 0;
        }
    }
    int calculateHappiness() override {
        return (age*weight*3);
    }
};

#endif //AC_PROJECT5_HOUSECAT_H


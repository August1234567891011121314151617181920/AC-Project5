//
// Created by xenon on 3/21/2020.
//

#ifndef AC_PROJECT5_ALLIGATOR_H
#define AC_PROJECT5_ALLIGATOR_H
#include "Animal.h"

class Alligator : public Animal{
public:
    //contstructors
    Alligator(int age, float weight, string name, bool albino){
        setTimesFed(0);
        setAge(age);
        setWeight(weight);
        setName(name);
        setAlbino(albino);
    }
    //virtual methods
    virtual void animalCall(){
        cout << "*Alligator Noise*" << endl;
    }
    virtual void feedAnimal(){
        setTimesFed(timesFed+1);
        redoAnimalWeight();
    }
    virtual void redoAnimalWeight(){
        if(timesFed == 10){
            weight = weight*1.05;
            timesFed = 0;
        }
    }
    int calculateHappiness() override {
        return (age*weight*0);
    }
    //other Methods

};

#endif //AC_PROJECT5_ALLIGATOR_H

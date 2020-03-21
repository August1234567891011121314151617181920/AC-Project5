//
// Created by xenon on 3/21/2020.
//

#ifndef AC_PROJECT5_DOGGO_H
#define AC_PROJECT5_DOGGO_H

#include "Animal.h"

class Doggo : public Animal{
public:
    //contstructors
    Doggo(int age, float weight, string name, bool albino){
        setTimesFed(0);
        setAge(age);
        setWeight(weight);
        setName(name);
        setAlbino(albino);
    }
    //virtual methods
    void animalCall() override {
        cout << "Woof!" << endl;
    }
    void feedAnimal() override {
        setTimesFed(timesFed+1);
        redoAnimalWeight();
    }
    void redoAnimalWeight() override {
        if(timesFed == 5){
            weight = weight*1.5;
            timesFed = 0;
        }
    }
    int calculateHappiness() override {
        return (age*weight*6);
    }

    //other methods
    void tailWag(){
        cout << "*wag wag wag*" << endl;
    }


};

#endif //AC_PROJECT5_DOGGO_H


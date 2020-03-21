//
// Created by xenon on 3/21/2020.
//

#ifndef AC_PROJECT5_ANIMAL_H
#define AC_PROJECT5_ANIMAL_H

#include <string>

using namespace std;

class Animal {
protected:
    int timesFed;
    int age;
    float weight;
    string name;
    bool albino;

public:
    //getters
    int getTimesFed() const{
        return timesFed;
    }
    int getAge() const{
        return age;
    }
    float getWeight() const{
        return weight;
    }
    string getName() const{
        return name;
    }
    bool getAlbino() const{
        return albino;
    }

    //setters
    void setTimesFed(int f){
        timesFed = f;
    }
    void setAge(int a){
        age = a;
    }
    void setWeight(float w){
        weight = w;
    }
    void setName(string n){
        name = n;
    }
    void setAlbino(bool b){
        albino = b;
    }

    //virtual functions
    virtual void animalCall() = 0;

    virtual void feedAnimal() = 0;

    virtual void redoAnimalWeight() = 0;

    virtual int calculateHappiness() = 0;

    //destructor
    virtual ~Animal(){}
};

#endif //AC_PROJECT5_ANIMAL_H

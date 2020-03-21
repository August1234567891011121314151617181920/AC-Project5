//
// Created by xenon on 3/21/2020.
//

#ifndef AC_PROJECT5_ANIMAL_H
#define AC_PROJECT5_ANIMAL_H

#endif //AC_PROJECT5_ANIMAL_H
#include <string>

using namespace std;

class Animal {
protected:
    int timesFed;
    int weight;
    string name;
    bool albino;

public:
    //getters
    int getTimesFed(){
        return timesFed;
    }
    int getWeight(){
        return weight;
    }
    string getName(){
        return name;
    }
    bool getAlbino(){
        return albino;
    }
    //setters
    void setTimesFed(int f){
        timesFed = f;
    }
    void setWeight(int w){
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

    //destructor
    virtual ~Animal(){}
};
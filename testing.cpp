//
// Created by xenon on 3/21/2020.
//
#include <iostream>
#include <string>
#include "Alligator.h"
#include "Doggo.h"
#include "HouseCat.h"

bool alligatorTest();
bool alligatorTestHelper(Alligator alligator1, int timesFed, int expectedHappiness, float expectedWeight);
bool catTest();
bool catTestHelper(HouseCat cat1, int timesFed, int expectedHappiness, float expectedWeight);
bool dogTest();
bool dogTestHelper(Doggo dog1, int timesFed, int expectedHappiness, float expectedWeight);

using namespace std;
int main() {
    cout << "Testing Alligator" << endl;
    alligatorTest();
    cout << "Testing Cat" << endl;
    catTest();
    cout << "Testing Dog" << endl;
    dogTest();
    return 0;
}

bool alligatorTest(){
    Alligator alligator1 = Alligator(50,500,"Timmy",false);
    if(!alligatorTestHelper(alligator1,9,0,alligator1.getWeight()*1.05)){
        cout << "Alligator test Case 1 Failed" << endl;
        return false;
    }
    if(!alligatorTestHelper(alligator1,8,0, 500)){
        cout << "Alligator test Case 2 Failed" << endl;
        return false;
    }
    if(!alligatorTestHelper(alligator1,400,0, 500*1.05)){
        cout << "Alligator test Case 3 Failed" << endl;
        return false;
    }
    return true;
}
bool alligatorTestHelper(Alligator alligator1, int timesFed, int expectedHappiness, float expectedWeight){
    alligator1.setTimesFed(timesFed);
    alligator1.feedAnimal();
    int happiness = alligator1.calculateHappiness();
    if(happiness != expectedHappiness or expectedWeight != alligator1.getWeight()){
        return false;
    }
    else{
        return true;
    }
}

bool catTest(){
    HouseCat cat1 = HouseCat(10,9,"Reginald",false);
    if(!catTestHelper(cat1,2,337,9*1.25)){
        cout << "Cat test Case 1 Failed" << endl;
        return false;
    }
    if(!catTestHelper(cat1,1,270,9)){
        cout << "Cat test Case 2 Failed" << endl;
        cout << cat1.calculateHappiness();
        return false;
    }
    return true;
}
bool catTestHelper(HouseCat cat1, int timesFed, int expectedHappiness, float expectedWeight){
    cat1.setTimesFed(timesFed);
    cat1.feedAnimal();
    int happiness = cat1.calculateHappiness();
    if(happiness != expectedHappiness or expectedWeight != cat1.getWeight()){
        return false;
    }
    else{
        return true;
    }
}

bool dogTest(){
    Doggo dog1 = Doggo(12,50,"Rex",false);
    if(!dogTestHelper(dog1,4,5400,50*1.5)){
        cout << "Dog test Case 1 Failed" << endl;
        return false;
    }
    if(!dogTestHelper(dog1,1,3600,50)){
        cout << "Dog test Case 2 Failed" << endl;
        cout << dog1.calculateHappiness();
        return false;
    }
    return false;
}
bool dogTestHelper(Doggo dog1, int timesFed, int expectedHappiness, float expectedWeight){
    dog1.setTimesFed(timesFed);
    dog1.feedAnimal();
    int happiness = dog1.calculateHappiness();
    if(happiness != expectedHappiness or expectedWeight != dog1.getWeight()){
        return false;
    }
    else{
        return true;
    }
}
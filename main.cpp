#include <memory>
#include <iostream>
#include <vector>
#include "Alligator.h"
#include "Doggo.h"
#include "HouseCat.h"



using namespace std;

void printStats(Alligator alligator);
void printStats(HouseCat cat);
void printStats(Doggo dog);
void makeAlligator(vector<unique_ptr<Animal>> &vector);
void makeCat(vector<unique_ptr<Animal>> &vector);
void makeDog(vector<unique_ptr<Animal>> &vector);

int main() {
    vector<unique_ptr<Animal>> vect;
    int userChoice = 0;

    //this starting bit demonstrates the program
    cout << "This program is about building animals." << endl;
    cout << "When you build animals they are put into a vector and I show polymorphism on them later."<<endl;
    cout << "If you dont want to build a bunch of animals just uncomment some code at the bottom of main " << endl;
    cout << "and they will be build automatically." << endl;
    cout << "Would you like to build an animal? 1 for yes or 0 for no" << endl;
    cin >> userChoice;

    while (userChoice == 1) {
        userChoice = 99;
        while (userChoice > 3 or userChoice < 1) {
            cout << "which Animal would you like? 1 for alligator, 2 for cat, 3 for dog" << endl;
            cin >> userChoice;
        }
        if (userChoice == 1) {
            makeAlligator(vect);
        } else if (userChoice == 2) {
            makeCat(vect);
        } else if (userChoice == 3) {
            makeDog(vect);
        }

        cout << "Would you like to build another animal? 1 for yes or 0 for no" << endl;
        cin >> userChoice;
    }
    cout << "**************Enough of those shenanigans. On to polymorphism***************" << endl << endl;
    //this is where i will demonstrate the polymorphism
    //NOTE: if you dont want to have to input all the animals you can just uncomment this
//    Alligator alligator1 = Alligator(20,1000,"John",false);
//    Alligator alligator2 = Alligator(15,100,"Jim",false);
//    HouseCat houseCat1 = HouseCat(10,10,"Reginald",false);
//    HouseCat houseCat2 = HouseCat(1,4,"Yung Mike",false);
//    Doggo dog1 = Doggo(10,50,"Rex",false);
//    Doggo dog2 = Doggo(1,7,"Greg",false);
//    vector.push_back(make_unique<Alligator>(alligator1));
//    vector.push_back(make_unique<HouseCat>(houseCat1));
//    vector.push_back(make_unique<Doggo>(dog1));
//    vector.push_back(make_unique<Alligator>(alligator2));
//    vector.push_back(make_unique<HouseCat>(houseCat2));
//    vector.push_back(make_unique<Doggo>(dog2));


//this right here is the polymorphism. it loops through the vector of animals
//you made and calls the animalcall method on each one.
    for(int i = 0 ; i < vect.size(); ++i){
        vect[i]->animalCall();
    }




    return 0;
}

void printStats(Alligator alligator){
    cout << "ALLIGATOR STATS:" << endl;
    cout << "Name: " << alligator.getName()<< endl;
    cout << "Age: " << alligator.getAge()<< endl;
    cout << "Weight: " << alligator.getWeight()<< endl;
    cout << "Albino: " << boolalpha <<alligator.getAlbino()<< endl;
}
void printStats(HouseCat cat){
    cout << "CAT STATS:" << endl;
    cout << "Name: " << cat.getName()<< endl;
    cout << "Age: " << cat.getAge()<< endl;
    cout << "Weight: " << cat.getWeight()<< endl;
    cout << "Albino: " << boolalpha <<cat.getAlbino()<< endl;
}
void printStats(Doggo dog){
    cout << "CAT STATS:" << endl;
    cout << "Name: " << dog.getName()<< endl;
    cout << "Age: " << dog.getAge()<< endl;
    cout << "Weight: " << dog.getWeight()<< endl;
    cout << "Albino: " << boolalpha <<dog.getAlbino()<< endl;
}

void makeAlligator(vector<unique_ptr<Animal>> &vect){
    string name;
    int age;
    float weight;
    bool albino;
    int userChoice;

    cout << "You want an alligator? ok." << endl;
    cout << "What Should its Name be?" << endl;
    cin >> name;
    cout << "What is its weight?" << endl;
    cin >> weight;
    cout << "What is its Age?" << endl;
    cin >> age;
    cout << "Is it albino? (enter 0 for false and 1 for true)" << endl;
    cin >> albino;
    Alligator alligator = Alligator(age,weight,name,albino);
    cout << "Would you like to feed him/her? (If you feed them enough they grow) 1 for yes and 0 for no" << endl;
    cin >> userChoice;
    while(userChoice != 0){
        alligator.feedAnimal();
        alligator.animalCall();
        printStats(alligator);
        cout << "If you want to stop feeding "<< name << " type 0." << endl;
        cin >> userChoice;
    }
    vect.push_back(make_unique<Alligator>(alligator));
}
void makeCat(vector<unique_ptr<Animal>> &vect){
    string name;
    int age;
    float weight;
    bool albino;
    int userChoice;

    cout << "You want a cat? ok." << endl;
    cout << "What Should its Name be?" << endl;
    cin >> name;
    cout << "What is its weight?" << endl;
    cin >> weight;
    cout << "What is its Age?" << endl;
    cin >> age;
    cout << "Is it albino? (enter 0 for false and 1 for true)" << endl;
    cin >> albino;
    HouseCat cat = HouseCat(age,weight,name,albino);
    cout << "Would you like to feed him/her? (If you feed them enough they grow) 1 for yes and 0 for no" << endl;
    cin >> userChoice;
    while(userChoice != 0){
        cat.feedAnimal();
        cat.animalCall();
        printStats(cat);
        cout << "If you want to stop feeding "<< name << " type 0." << endl;
        cin >> userChoice;
    }
    vect.push_back(make_unique<HouseCat>(cat));
}
void makeDog(vector<unique_ptr<Animal>> &vect){
    string name;
    int age;
    float weight;
    bool albino;
    int userChoice;

    cout << "You want a dog? ok." << endl;
    cout << "What Should its Name be?" << endl;
    cin >> name;
    cout << "What is its weight?" << endl;
    cin >> weight;
    cout << "What is its Age?" << endl;
    cin >> age;
    cout << "Is it albino? (enter 0 for false and 1 for true)" << endl;
    cin >> albino;
    Doggo dog = Doggo(age,weight,name,albino);
    cout << "Would you like to feed him/her? (If you feed them enough they grow) 1 for yes and 0 for no" << endl;
    cin >> userChoice;
    while(userChoice != 0){
        dog.feedAnimal();
        dog.animalCall();
        printStats(dog);
        cout << "If you want to stop feeding "<< name << " type 0." << endl;
        cin >> userChoice;
    }
    vect.push_back(make_unique<Doggo>(dog));
}
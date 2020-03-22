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
    string userChoice = "yes";

    //this starting bit demonstrates the program
    cout << "This program is about building animals." << endl;
    cout << "When you build animals they are put into a vector and I show polymorphism on them later."<<endl;
    cout << "If you dont want to build a bunch of animals just uncomment some code at the bottom of main " << endl;
    cout << "and they will be build automatically." << endl;
    cout << "Would you like to build an animal? 'yes' or 'no'" << endl;
    cin >> userChoice;
    while(userChoice != "yes" and userChoice != "no"){
        cout << "Please type 'yes' or 'no'" << endl;
        cin >> userChoice;
    }

    while (userChoice == "yes") {
        userChoice = "";
        cout << "Which animal would you like? Type 'alligator', 'cat', or 'dog'" << endl;
        cin >> userChoice;
        while (userChoice != "alligator" and userChoice != "cat" and userChoice != "dog") {
            cout << "Please type 'alligator', 'cat', or 'dog'" << endl;
            cin >> userChoice;
        }
        if (userChoice == "alligator") {
            makeAlligator(vect);
        } else if (userChoice == "cat") {
            makeCat(vect);
        } else if (userChoice == "dog") {
            makeDog(vect);
        }

        cout << "Would you like to build another animal? 'yes' or 'no'" << endl;
        cin >> userChoice;
        while(userChoice != "yes" and userChoice != "no"){
            cout << "Please type 'yes' or 'no'" << endl;
            cin >> userChoice;
        }
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
//    vect.push_back(make_unique<Alligator>(alligator1));
//    vect.push_back(make_unique<HouseCat>(houseCat1));
//    vect.push_back(make_unique<Doggo>(dog1));
//    vect.push_back(make_unique<Alligator>(alligator2));
//    vect.push_back(make_unique<HouseCat>(houseCat2));
//    vect.push_back(make_unique<Doggo>(dog2));


//this right here is the polymorphism. it loops through the vector of animals
//you made and calls the animalcall method on each one.
    for(int i = 0 ; i < vect.size(); ++i){
        vect[i]->animalCall();
    }




    return 0;
}
//these print the animal attributes
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

//these make a particular animal and put it in the vector at the end
void makeAlligator(vector<unique_ptr<Animal>> &vect){
    string name;
    int age;
    float weight;
    string userChoice;

    cout << "You want an alligator? ok." << endl;
    cout << "What Should its Name be?" << endl;
    cin >> name;
    cout << "What is its weight?" << endl;
    cin >> weight;
    while(weight <= 0){
        cout << "Please input a real weight value" << endl;
        cin >> weight;
    }
    cout << "What is its Age?" << endl;
    cin >> age;
    while(age <= 0){
        cout << "Please input a real age value" << endl;
        cin >> age;
    }
    Alligator alligator = Alligator(age,weight,name,false);
    cout << "Would you like to feed him/her? (If you feed them enough they grow) 'yes' or 'no'" << endl;
    cin >> userChoice;
    while(userChoice != "yes" and userChoice != "no"){
        cout << "Please type 'yes' or 'no'" << endl;
        cin >> userChoice;
    }
    while(userChoice == "yes"){
        alligator.feedAnimal();
        alligator.animalCall();
        printStats(alligator);
        cout << "Would you like to feed him/her again? 'yes' or 'no'" << endl;
        cin >> userChoice;
        while(userChoice != "yes" and userChoice != "no"){
            cout << "Please type 'yes' or 'no'" << endl;
            cin >> userChoice;
        }
    }
    vect.push_back(make_unique<Alligator>(alligator));
}
void makeCat(vector<unique_ptr<Animal>> &vect){
    string name;
    int age;
    float weight;
    string userChoice;

    cout << "You want a cat? ok." << endl;
    cout << "What Should its Name be?" << endl;
    cin >> name;
    cout << "What is its weight?" << endl;
    cin >> weight;
    while(weight <= 0){
        cout << "Please input a real weight value" << endl;
        cin >> weight;
    }
    cout << "What is its Age?" << endl;
    cin >> age;
    while(age <= 0){
        cout << "Please input a real age value" << endl;
        cin >> age;
    }
    HouseCat cat = HouseCat(age,weight,name,false);
    cout << "Would you like to feed him/her? (If you feed them enough they grow) 'yes' or 'no'" << endl;
    cin >> userChoice;
    while(userChoice != "yes" and userChoice != "no"){
        cout << "Please type 'yes' or 'no'" << endl;
        cin >> userChoice;
    }
    while(userChoice == "yes"){
        cat.feedAnimal();
        cat.animalCall();
        printStats(cat);
        cout << "Would you like to feed him/her again? 'yes' or 'no'" << endl;
        cin >> userChoice;
        while(userChoice != "yes" and userChoice != "no"){
            cout << "Please type 'yes' or 'no'" << endl;
            cin >> userChoice;
        }
    }
    vect.push_back(make_unique<HouseCat>(cat));
}
void makeDog(vector<unique_ptr<Animal>> &vect){
    string name;
    int age;
    float weight;
    string userChoice;

    cout << "You want a dog? ok." << endl;
    cout << "What Should its Name be?" << endl;
    cin >> name;
    cout << "What is its weight?" << endl;
    cin >> weight;
    while(weight <= 0){
        cout << "Please input a real weight value" << endl;
        cin >> weight;
    }
    cout << "What is its Age?" << endl;
    cin >> age;
    while(age <= 0){
        cout << "Please input a real age value" << endl;
        cin >> age;
    }
    Doggo dog = Doggo(age,weight,name,false);
    cout << "Would you like to feed him/her? (If you feed them enough they grow) 'yes' or 'no'" << endl;
    cin >> userChoice;
    while(userChoice != "yes" and userChoice != "no"){
        cout << "Please type 'yes' or 'no'" << endl;
        cin >> userChoice;
    }
    while(userChoice == "yes"){
        dog.feedAnimal();
        dog.animalCall();
        printStats(dog);
        cout << "Would you like to feed him/her again? 'yes' or 'no'" << endl;
        cin >> userChoice;
        while(userChoice != "yes" and userChoice != "no"){
            cout << "Please type 'yes' or 'no'" << endl;
            cin >> userChoice;
        }
    }
    vect.push_back(make_unique<Doggo>(dog));
}
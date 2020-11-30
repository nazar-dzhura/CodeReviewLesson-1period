#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Musician {
private:
    string name;
    int age;
    double fee;

public:
    Musician() {};
    Musician(string new_name, double new_fee, int new_age) {
        this->name = new_name;
        this->fee = new_fee;
        this->age = new_age;
    };
    ~Musician() {};

    string getName() { return name; }
    double getFee() { return fee; }
    int getAge() { return age; }
};



class MusicFestival {
private:
    double budget = 0;
    vector <Musician> artists;
    double currentBudget = 0;

public:
    void addMusician(Musician a) {
        if (a.getFee() + currentBudget < budget) {
            artists.push_back(a);
            currentBudget = currentBudget + a.getFee();
            cout << "Artist "<< a.getName() <<" has been succesfully added to the list." << endl;
        }
        else {
            cout << "We can not afford this artist, but we still have "<< budget - currentBudget << " dollars." << endl;
        }
    }
    void removeMusician(Musician a) {
        artists.pop_back();
        cout << "Artist " << a.getName() << " has been removed from the list." << endl;
    }

    vector <Musician> getArtists() { return artists; }
    void SetBudget(double maxBudget) {
        budget = maxBudget;
    }

    MusicFestival() {
    };
    MusicFestival(vector<Musician> artist1, double maxBudget) {
        int i = 0; 
        budget = maxBudget;
        double artist1budget = 0;
        for (i = 0; i < artist1.size(); i++) {
            artist1budget = artist1budget + artist1.at(i).getFee();
                
        }
        if (artist1budget > budget) {
            cout << "You cant afford this artist." << endl;
        }
        else {
            for (int i = 0; i < artist1.size(); i++) {
                artists.push_back(artist1.at(i));
            }
        }
    }
    ~MusicFestival() {};
};



int main() {
    double maxBudget = 0;
    cout << "Enter available budget in dollars: \n" << endl;
    cin >> maxBudget;
    MusicFestival festival1;
    festival1.SetBudget(maxBudget);


    Musician number1("Travis Scott", 1500000, 29);
    Musician number2("Tory Lanez", 750000, 28);
    Musician number3("A$AP Rocky", 1400000, 32);
    Musician number4("SAINt JHN", 800000, 34);
    Musician number5("Lil Uzi Vert", 700000, 26);
    Musician number6("Post Malone", 1200000, 25);
    Musician number7("Tyler, The Creator", 1350000, 29);
    Musician number8("Denzel Curry", 750000, 25);

    

    festival1.addMusician(number1);
    festival1.addMusician(number2);
    festival1.addMusician(number3);
    festival1.addMusician(number4);
  
    cout << "\nAdded " << festival1.getArtists().size() << " artist(s) in all." << endl;
}


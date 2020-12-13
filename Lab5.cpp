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
        Musician(string newName, double newFee, int newAge) {
            this->name = newName;
            this->fee = newFee;
            this->age = newAge;
        };
        ~Musician() {};

        string getName() {
            return name;
        }
        double getFee() {
            return fee;
        }
        int getAge() {
            return age;
        }
    };

class MusicFestival {
    private:
        double budget = 0;
        vector <Musician> artists;
        double currentBudget = 0;

    public:
        void addMusician(Musician artist) {
            if (artist.getFee() + currentBudget < budget) {
                artists.push_back(artist);
                currentBudget = currentBudget + artist.getFee();
                cout << "Artist " << artist.getName() << " has been succesfully added to the list." << endl;
            }
            else {
                cout << "We can not afford this artist, but we still have " << budget - currentBudget << " dollars." << endl;
            }
        }
        void removeMusician(Musician artist) {
            artists.pop_back();
            cout << "Artist " << artist.getName() << " has been removed from the list." << endl;
            currentBudget = currentBudget - artist.getFee();
        }

        vector <Musician> getArtists() {
            return artists;
        }
        void setBudget(double newBudget) {
            budget = newBudget;
        }

        MusicFestival() {};
        MusicFestival(vector<Musician> newArtists, double newBudget) {
            int i = 0;
            budget = newBudget;
            double newArtistsBudget = 0;
            for (i = 0; i < newArtists.size(); i++) {
                newArtistsBudget = newArtistsBudget + newArtists.at(i).getFee();

            }
            if (newArtistsBudget > budget) {
                cout << "You cant afford this artist." << endl;
            }
            else {
                for (i = 0; i < newArtists.size(); i++) {
                    artists.push_back(newArtists.at(i));
                }
            }
        }
        ~MusicFestival() {};
    };

int main() {
    double newBudget = 0;
    cout << "Enter available budget in dollars: \n" << endl;
    cin >> newBudget;
    MusicFestival festival1;
    festival1.setBudget(newBudget);

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

    return 0;
}

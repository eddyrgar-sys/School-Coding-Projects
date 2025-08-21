// Week 1 HW.cpp

#include <iostream>
#include <string>

class Flower {
private:
    std::string name; // Name of the flower
    int numPetals;    // Number of petals
    float price;      // Price of the flower

public:
    // Constructor to initialize member variables
    Flower(const std::string& flowerName = "Unknown", int petals = 0, float flowerPrice = 0.0f)
        : name(flowerName), numPetals(petals), price(flowerPrice) {}

    // Setter for name
    void setName(const std::string& flowerName) {
        name = flowerName;
    }

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for number of petals
    void setNumPetals(int petals) {
        numPetals = petals;
    }

    // Getter for number of petals
    int getNumPetals() const {
        return numPetals;
    }

    // Setter for price
    void setPrice(float flowerPrice) {
        price = flowerPrice;
    }

    // Getter for price
    float getPrice() const {
        return price;
    }
};

int main() {
    // Create a Flower object
    Flower rose("Rose", 32, 12.99f);

    // Print initial values
    std::cout << "Flower Name: " << rose.getName() << std::endl;
    std::cout << "Number of Petals: " << rose.getNumPetals() << std::endl;
    std::cout << "Price: $" << rose.getPrice() << std::endl;

    // Modify values using setters
    rose.setName("Tulip");
    rose.setNumPetals(6);
    rose.setPrice(8.49f);

    // Print updated values
    std::cout << "\nUpdated Flower Information:" << std::endl;
    std::cout << "Flower Name: " << rose.getName() << std::endl;
    std::cout << "Number of Petals: " << rose.getNumPetals() << std::endl;
    std::cout << "Price: $" << rose.getPrice() << std::endl;

    return 0;
}


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Shooter 
{
public:
    string name;
    int bulletCount;
    int initialBulletCount;

    Shooter(string name, int bullets) 
    {
        this->name = name;
        this->bulletCount = bullets;
        this->initialBulletCount = bullets;
    }

    void shooting() 
    {
        if (bulletCount > 0)
            bulletCount--;
    }

    string getName() 
    {
        return name;
    }

    int getQuantity() 
    {
        return bulletCount;
    }

    void display() 
    {
        cout << "Shooter Name: " << name << ", Remaining Bullets: " << bulletCount << endl;
    }
};

class Queue 
{
private:
    struct Node 
    {
        Shooter data;
        Node* next;
        Node(Shooter shooter) : data(shooter), next(nullptr) {}
    };
    Node* frontNode;
    Node* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    bool empty() 
    {
        return frontNode == nullptr;
    }

    void enqueue(Shooter shooter) 
    {
        Node* newNode = new Node(shooter);
        if (rearNode) 
        {
            rearNode->next = newNode;
        }
        else 
        {
            frontNode = newNode;
        }
        rearNode = newNode;
    }

    void dequeue() 
    {
        if (!empty()) 
        {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            if (!frontNode) 
            {
                rearNode = nullptr;
            }
            delete temp;
        }
    }

    Shooter front() 
    {
        if (!empty()) 
        {
            return frontNode->data;
        }
        throw runtime_error("Queue is empty");
    }
};

int main() 
{
    Queue shootingRange;
    ifstream inputFile("Week3-bulletCount.txt");
    string name;
    int bullets;

    if (!inputFile) 
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    while (inputFile >> name >> bullets) 
    {
        Shooter shooter(name, bullets);
        shootingRange.enqueue(shooter);
        cout << "Shooter Added - Name: " << name << ", Bullets: " << bullets << endl;
    }
    inputFile.close();

    cout << "\nStarting Shooting Simulation...\n";
    while (!shootingRange.empty()) 
    {
        Shooter currentShooter = shootingRange.front();
        shootingRange.dequeue();
        currentShooter.shooting();

        if (currentShooter.getQuantity() == 0) 
        {
            cout << "Shooter " << currentShooter.getName() << " has finished shooting." << endl;
        }
        else 
        {
            cout << "Shooter " << currentShooter.getName() << " needs to shoot "
                << currentShooter.getQuantity() << " more bullets." << endl;
            shootingRange.enqueue(currentShooter);
            cout << "Shooter " << currentShooter.getName() << " sent back to queue." << endl;
        }
    }

    cout << "\nShooting Simulation Complete." << endl;
    return 0;
}

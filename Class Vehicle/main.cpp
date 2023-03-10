#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    public:
        Vehicle() {
            speed = 30;         //30/100
            coordinate = 0;
            capacity = 1;
        }

        Vehicle(unsigned int Speed, int Coordinate, unsigned int Capacity) {
            speed = Speed;
            coordinate = Coordinate;
            capacity = Capacity;
        }

        void Move(int distance) {
            coordinate += distance;
            cout << distance / speed << "sec lasted" << endl;
        }

    public:
        unsigned int speed;
        int coordinate;
        unsigned int capacity;
};

class Car: public Vehicle
{
    public:
        void Beep() {
            cout << "Beep-beep!" << endl;
        }

        unsigned int getGasQuantity() {
            return gasQuantity;
        }

        void setGasQuantity(int N) {
            gasQuantity = N;
        }

        void Refuel() {
            unsigned int i = getGasQuantity();
            if (i < 50) {
                setGasQuantity(100);
            }
        }

        void Move(int distance) {
            coordinate += distance;
            gasQuantity = gasQuantity - 0.01*speed*distance;
            cout << distance / speed << "sec lasted" << endl;
        }

    private:
        unsigned int gasQuantity = 100;
};

class PassangerCar: public Car
{
    private:
        string model;
};

class Horse: protected Vehicle
{
    public:
        Horse() {
            speed = 30;
            coordinate = 0;
            capacity = 1;
        }

        void Eat() {isHungry = false;}

        void Sleep() {isTired = false;}

        void Move(int distance) {
            if (!isHungry && !isTired) {
                coordinate += distance;
                cout << distance / speed << "sec lasted" << endl;
                if (distance > 1000) {
                    isHungry = true;
                    isTired = true;
                }
            }
            else {
                if (isHungry)
                    Eat();
                if (isTired)
                    Sleep();
            }
        }

        bool isHungry = false;
        bool isTired = false;
};

int main()
{
    Horse horse;
    horse.Move(240);

    PassangerCar Renault;
    Renault.Beep();
    Renault.Move(500);

    return 0;
}

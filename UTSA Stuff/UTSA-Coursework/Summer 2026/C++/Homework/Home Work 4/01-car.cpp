/*Problem 1  — Car ADT (40 pts)*/

#include <iostream>
using namespace std;

class Car {
  int gear = 1;
  int lane = 1;
  int speed = 0;
  string make;
  string model;

public:
  Car(string make_in, string model_in){
    make = make_in;
    model = model_in;

  };
  //Getters

    string getMake() const{
            return make;
    }

    string getModel() const{
            return model;
    }

    int getGear() const{
            return gear;
    }

    int getLane() const{
            return lane;
    }

    int getSpeed() const{
            return speed;
    }

    void display() const{
        
        cout << make << " " << model << " | Gear: " << gear << " | Lane: " << lane << " | " << speed << " mph" << endl;
    }

  // gear shifters
  void gearUp() {
        gear++;
        if (gear > 6) {
            cout << "Invalid gear" << endl;
            gear--; // Revert the gear change
        }
  }

  void gearDown() {
        gear--;
        if (gear < 1) {
            cout << "Invalid gear" << endl;
            gear++; // Revert the gear change
            
        }
  }

  //lane shifters
  void LaneLeft() { //lane 3 is farthest right lane
        lane--;
    if (lane < 1) {
            cout << "Invalid Lane shift" << endl;
        lane++; // Revert the lane change
        }
  }
  void LaneRight() { //lane 1 is farthest left lane
        lane++;
    if (lane > 3) {
            cout << "Invalid Lane shift" << endl;
        lane--; // Revert the lane change
        }
  }

// speed shifters max speed is 200 mph and min speed is 0 mph
  void speedUp() {
        speed += 5;
        if (speed > 200) {
            cout << "Invalid speed change" << endl;
            speed -= 5;
        }
  }

    void speedDown() {
        speed -= 5;
        if ( speed < 0) {
                cout << "speed is below minimum" << endl;
                speed = 0;
            }
    }

};
int main() {
   /* cout << "Hello driver!!" << endl;
    cout << "You are now driving a car. You have 6 gears, a speed limit of 200 mph," << endl;
    cout << "and you can shift lanes left and right. The left lane is 1 and the right lane is 3." << endl;*/

    Car myCar("Toyota", "Corolla");
    
    //initial display of the car's state
    myCar.display();
    
    //first set of changes
    myCar.speedUp();
    myCar.speedUp();
    myCar.gearUp();
    myCar.LaneRight();
    myCar.display();

    // second set of changes
    myCar.speedDown();
    myCar.gearDown();
    myCar.LaneLeft();
    myCar.display();
}
 
#include <iostream>
using namespace std;

struct Time{//military time, no am/pm
int hour;
int minute;
};

Time earlier(Time t1, Time t2){
    Time ret;
    if(t1.hour == t2.hour){
        if(t1.minute<t2.minute)
            ret = t1;
        else
            ret = t2;
    }
    else if(t1.hour<t2.hour){
        ret = t1;
    }
    else{
        ret = t2;
    }
    return ret;
}

class Carpool{
public:
  string names[5];
  int size;
  Time arrival;
  void print_car(){
    cout<<"The people in the car are:"<<endl;
    for(int i = 0; i < size; i++){
      cout<<names[i]<<endl;
    }
  }

};


Carpool combineCarpool(Carpool car1, Carpool car2){
  int combSize = car1.size + car2.size;
  Carpool new_Car;
  if(combSize <= 5){
    new_Car.size = combSize;


    for(int i  = 0; i < car1.size; i++){
      new_Car.names[i] = car1.names[i];
    }

    for(int i  = 0; i < car2.size; i++){
      new_Car.names[car1.size + i] = car2.names[i];
    }


    if(car1.arrival.hour > car2.arrival.hour){
      new_Car.arrival.hour = car2.arrival.hour;
      new_Car.arrival.minute = car2.arrival.minute;
    }
    else if (car1.arrival.hour < car2.arrival.hour){
      new_Car.arrival.hour = car1.arrival.hour;
      new_Car.arrival.minute = car1.arrival.minute;
    }
    else{
      if(car1.arrival.minute > car2.arrival.minute){
        new_Car.arrival.hour = car2.arrival.hour;
        new_Car.arrival.minute = car2.arrival.minute;
      }
      else{
        new_Car.arrival.hour = car1.arrival.hour;
        new_Car.arrival.minute = car1.arrival.minute;
      }
    }
  }
  else{
    cout << "Unable to combine carpools" << endl;
    new_Car.size = 0;
    return new_Car;
  }
  return new_Car;
}



int main() {
  Carpool car1, car2, result;
  int counter = 0;
  string input;

  cout<<"Enter the names for car 1 (-1 when done)"<<endl;
  cin >> input;

  while (input != "-1") {
    car1.names[counter] = input;
    counter++;
    cout<<"Enter the names for car 1 (-1 when done)"<<endl;
    cin >> input;
  }
  cout<<"enter the hour car 1 arrived"<<endl;
  cin>>car1.arrival.hour;
  cout<<"enter the minute car 1 arrived"<<endl;
  cin>>car1.arrival.minute;
  int counter2 = 0;
  string input2;
  cout<<"Enter the names for car 2 (-1 when done)"<<endl;
  cin >> input2;

  while (input2 != "-1") {
    car2.names[counter2] = input2;
    counter2++;
    cout<<"Enter the names for car 2 (-1 when done)"<<endl;
    cin >> input2;
  }

  cout<<"enter the hour car 2 arrived"<<endl;
  cin>>car2.arrival.hour;
  cout<<"enter the minute car 2 arrived"<<endl;
  cin>>car2.arrival.minute;
  car1.size = counter;
  car2.size = counter2;

  result = combineCarpool(car1,car2);
  cout << "New carpool size: " << result.size << " Group members: "<<endl;
  result.print_car();
  std::cout << "" << endl;
  cout<<"the time arrived is: "<<result.arrival.hour<<":"<<result.arrival.minute<<endl;
  return 0;
}

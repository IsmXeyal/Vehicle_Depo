#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

#include"Vehicle.h"

int main() {
    Engine engine1("E001", "Engine Company_1", 3.5);
    Engine engine2("F343", "Engine Company_2", 4.1);
    Engine engine3("X199", "Engine Company_3", 6.4);
    Engine engine4("S889", "Engine Company_4", 7.2);
    Engine engine5("Fx995", "Engine Company_5", 7.5);
    Engine engine6("E1201", "Engine Company_6", 8.2);

    Car car1("Car Model_1", "Car Vendor_1", engine1, true);
    Car car2("Car Model_2", "Car Vendor_2", engine2, false);
    Ship ship1("Ship Model_1", "Ship Vendor_1", engine3, false);
    Ship ship2("Ship Model_2", "Ship Vendor_2", engine4, true);
    Airplane airplane1("Airplane Model_1", "Airplane Vendor_1", engine5, 6, 200);
    Airplane airplane2("Airplane Model_2", "Airplane Vendor_2", engine6, 8, 345);

    VehicleDepo depo;

    depo.AddCar(car1);
    depo.AddCar(car2);
    depo.AddShip(ship1);
    depo.AddShip(ship2);
    depo.AddAirplane(airplane1);
    depo.AddAirplane(airplane2);

    depo.ShowAllVehicles();

	return 0;
}
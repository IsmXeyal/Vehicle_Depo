#pragma once

class Engine {
private:
    string _engine_no;
    string _company;
    double _volume;

public:
    Engine() = default;

    Engine(string engine_no, string company, double volume) {
        SetEngineNo(engine_no);
        SetCompany(company);
        SetVolume(volume);
    }

    string GetEngineNo() const {
        return this->_engine_no;
    }

    string GetCompany() const {
        return this->_company;
    }

    double GetVolume() const {
        return this->_volume;
    }

    void SetEngineNo(string engine_no) {
        if (engine_no.length() > 3) {
            this->_engine_no = engine_no;
            return;
        }
        assert(!"Wrong data!");
    }

    void SetCompany(string company) {
        if (company.length() > 3) {
            this->_company = company;
            return;
        }
        assert(!"Wrong data!");
    }

    void SetVolume(double volume) {
        if (volume > 2.0) {
            this->_volume = volume;
            return;
        }
        assert(!"Wrong data!");
    }

    void Show() {
        cout << "\tEngine Info" << endl
            << "Engine_No: " << this->GetEngineNo() << endl
            << "Company: " << this->GetCompany() << endl
            << "Volume: " << this->GetVolume() << endl;
    }
};

class Vehicle {
private:
    int _id = 0;
    string _model = "";
    string _vendor = "";
    Engine _engine;
    static int static_id;

public:
    Vehicle() {
        this->_id = static_id++;
    }

    Vehicle(string model, string vendor, Engine engine) {
        SetModel(model);
        SetVendor(vendor);
        SetEngine(engine);
        this->_id = static_id++;
    }

    int GetId() {
        return this->_id;
    }

    string GetModel() {
        return this->_model;
    }

    string GetVendor() {
        return this->_vendor;
    }

    Engine GetEngine() const {
        return this->_engine;
    }

    int GetStaticId() {
        return this->static_id;
    }

    void SetModel(string model) {
        if (model.length() > 3) {
            this->_model = model;
            return;
        }
        assert(!"Wrong data!!");
    }

    void SetVendor(string vendor) {
        if (vendor.length() > 3) {
            this->_vendor = vendor;
            return;
        }
        assert(!"Wrong data!!");
    }

    void SetEngine(Engine engine) {
        this->_engine = engine;
    }
    
    void Show() {
        cout << "ID: " << this->GetId() << endl
            << "Model: " << this->GetModel() << endl
            << "Vendor: " << this->GetVendor() << endl;
        cout << endl;
        this->_engine.Show();
        cout << endl;
    }
};

int Vehicle::static_id = 1;

class Car : virtual public Vehicle {
private:
    bool _hasSpoiler;

public:
    Car() = default;
    Car(string model, string vendor, Engine engine, bool hasSpoiler)
        : Vehicle(model, vendor, engine)
    {
        SetHasSpoiler(hasSpoiler);
    }

    bool GetHasSpoiler() {
        return this->_hasSpoiler;
    }

    void SetHasSpoiler(bool hasSpoiler) {
        this->_hasSpoiler = hasSpoiler;
    }

    void Show() {
        Vehicle::Show();
        cout << "Has Spoiler: " << ((this->GetHasSpoiler()) ? "Yes" : "No") << endl << endl;
    }
};

class Ship : virtual public Vehicle {
private:
    bool _hasSail;

public:
    Ship() = default;
    Ship(string model, string vendor, Engine engine, bool hasSail)
        : Vehicle(model, vendor, engine)
    {
        SetHasSail(hasSail);
    }

    bool GetHasSail() {
        return this->_hasSail;
    }

    void SetHasSail(bool hasSail) {
        this->_hasSail = hasSail;
    }

    void Show() {
        Vehicle::Show();
        cout << "Has Sail: " << (this->GetHasSail() ? "Yes" : "No") << endl << endl;
    }

};

class Airplane : virtual public Vehicle {
private:
    int _engineCount;
    int _passengersCapacity;

public:
    Airplane() = default;
    Airplane(string model, string vendor, Engine engine, int engineCount, int passengersCapacity)
        : Vehicle(model, vendor, engine)
    {
        SetEngineCount(engineCount);
        SetPassengersCapacity(passengersCapacity);
    }

    int GetEngineCount() {
        return this->_engineCount;
    }

    int GetPassengersCapacity() {
        return this->_passengersCapacity;
    }

    void SetEngineCount(int engineCount) {
        if (engineCount > 2) {
            this->_engineCount = engineCount;
            return;
        }
        assert(!"Wrong data!");
    }

    void SetPassengersCapacity(int passengersCapacity) {
        if (passengersCapacity > 150) {
            this->_passengersCapacity = passengersCapacity;
            return;
        }
        assert(!"Wrong data!");
    }

    void Show() {
        Vehicle::Show();
        cout << "Engine Count: " << this->GetEngineCount() << endl;
        cout << "Passengers Capacity: " << this->GetPassengersCapacity() << endl << endl;
    }
};

class VehicleDepo {
private:
    stack<Car> _cars;
    stack<Ship> _ships;
    stack<Airplane> _airplanes;

public:

    void AddCar(Car car) {
        this->_cars.push(car);
    }

    void AddShip(Ship ship) {
        this->_ships.push(ship);
    }

    void AddAirplane(Airplane airplane) {
        this->_airplanes.push(airplane);
    }

    void ShowAllVehicles() {
        cout << "~~~~~~~Cars~~~~~~~" << endl;
        while (!_cars.empty()) {
            Car car = _cars.top();
            car.Show();
            _cars.pop();
        }

        cout << "~~~~~~~Ships~~~~~~~" << endl;
        while (!_ships.empty()) {
            Ship ship = _ships.top();
            ship.Show();
            _ships.pop();
        }

        cout << "~~~~~~~Airplanes~~~~~~~" << endl;
        while (!_airplanes.empty()) {
            Airplane airplane = _airplanes.top();
            airplane.Show();
            _airplanes.pop();
        }
    }
};


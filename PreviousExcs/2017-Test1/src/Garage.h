/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>

#include "insertionSort.h"

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

class NoSuchBrandException {
private:
	string brand;
public:
	NoSuchBrandException(){}
	NoSuchBrandException(string b): brand(b){}
	string getBrand(){ return brand;}
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle){
	if(vehicles.size() < capacity){
		for(int i = 0; i < vehicles.size(); i++){
			if(vehicles.at(i) == vehicle)
				return false;
		}

		vehicles.push_back(vehicle);
		return true;
	}
	else
		return false;
}

template<class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model) {
	for(int i = 0; i < vehicles.size(); i++){
		if(vehicles.at(i)->getBrand().compare(brand) == 0 & vehicles.at(i)->getModel().compare(model) == 0){
			Vehicle *v = vehicles.at(i);
			vehicles.erase(vehicles.begin() + i);
			return v;
		}
	}

	throw NoSuchVehicleException();
}

template<class Vehicle>float Garage<Vehicle>::avgPrice(std::string brand) const {
	float sum = 0;
	int count = 0;

	for(int i = 0; i < vehicles.size(); i++){
		if(vehicles.at(i)->getBrand().compare(brand) == 0){
			sum += vehicles.at(i)->getPrice();
			count++;
		}
	}

	if(sum == 0)
		throw NoSuchBrandException(brand);

	sum /= (float)count;

	return sum;
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
	insertionSort(vehicles);
}


#endif /* SRC_GARAGE_H_ */

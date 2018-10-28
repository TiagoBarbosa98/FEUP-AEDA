/*
 * Postman.cpp
 */
#include "Postman.h"


Postman::Postman(): id(0) {}

void Postman::setName(string nm){
	name = nm;
}

string Postman::getName() const{
	return name;
}

vector<Mail *> Postman::getMail() const {
	return myMail;
}

void Postman::addMail(Mail *m) {
	myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
	myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
	return id;
}

bool Postman::operator ==(const Postman& p) const {
	return name.compare(p.getName()) == 0;
}

int Postman::allid = 1;

Postman::Postman(string name): name(name), id(allid){
	allid++;
}

bool Postman::operator <(const Postman& p) const {
	vector<string> zipCode1, zipCode2;

	for(Mail* m: myMail){
		zipCode1.push_back(m->getZipCode());
	}
	for(Mail* m: p.getMail()){
			zipCode2.push_back(m->getZipCode());
		}
	return numberDifferent(zipCode1) < numberDifferent(zipCode2);
}

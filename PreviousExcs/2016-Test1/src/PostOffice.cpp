/*
 * PostOffice.cpp
 */

#include "PostOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}

vector<Mail*> PostOffice::removePostman(string name) {
	vector<Mail*> ret;
	for(int i = 0; i < postmen.size(); i++){
		if(postmen.at(i).getName() == name){
			ret = postmen.at(i).getMail();
			postmen.erase(postmen.begin() + i);
		}
	}

	return ret;

}

vector<Mail*> PostOffice::endOfDay(unsigned int& balance) {
	balance = 0;
	vector<Mail*> otherMail;

	for(int i = 0; i < mailToSend.size(); i++){
		balance += mailToSend.at(i)->getPrice();

		if(mailToSend.at(i)->getZipCode() <= lastZipCode & mailToSend.at(i)->getZipCode() >= firstZipCode){
			addMailToDeliver(mailToSend.at(i));
		}
		else
			otherMail.push_back(mailToSend.at(i));
	}

	mailToSend.clear();

	return otherMail;
}

Postman PostOffice::addMailToPostman(Mail* m, string name) {
	for(Postman p: postmen){
		if(p.getName() == name){
			p.addMail(m);
			return p;
		}
	}

	throw NoPostmanException(name);
}

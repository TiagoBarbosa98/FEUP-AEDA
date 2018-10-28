/*
 * Mail.cpp
 */

#include "Mail.h"

Mail::Mail(string send, string rec, string zcode):
			sender(send),receiver(rec), zipCode(zcode)
{ }

Mail::~Mail()
{ }

string Mail::getZipCode() const {
	return zipCode;
}

RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w):
			Mail(send, rec, zcode), weight(w)
{ }

GreenMail::GreenMail(string send, string rec, string zcode, string t):
			Mail(send, rec, zcode), type(t)
 {
}

int RegularMail::getPrice() const {
	if(weight <= 20)
		return 50;
	else if(weight > 20 & weight <= 100)
		return 75;
	else if(weight > 100 & weight <= 500)
		return 140;
	else if(weight > 500)
		return 325;
	else
		return 0;
}

int GreenMail::getPrice() const {
	if(type.compare("envelope") == 0)
		return 80;
	else if(type.compare("bag") == 0)
		return 200;
	else if(type.compare("box") == 0)
		return 240;
	else
		return 0;
}

bool Mail::operator ==(const Mail& m) {
	return zipCode == m.getZipCode();
}

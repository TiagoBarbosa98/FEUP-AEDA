/*
 * Mail.h
 */

#ifndef SRC_MAIL_H_
#define SRC_MAIL_H_

#include <string>>
#include <vector>
#include <set>
using namespace std;

//50 cent, se p<=20g ; 75 cent, se 20<p<=100g
//140 cent, se 100<p<=500g ; 325 cent, se p>500

//80 cent, se envelope (envelope) ; 200 cent, se saqueta (bag)
//240 cent, se caixa de cartão (box)


class Mail {
	string sender;
	string receiver;
	string zipCode;
public:
	Mail(string send, string rec, string zcode);
	virtual ~Mail();
	string getZipCode() const;
	virtual int getPrice() const = 0;
	bool operator == (const Mail &m);
};


class RegularMail: public Mail {
	unsigned int weight;
public:
	RegularMail(string send, string rec, string code, unsigned int w);
	int getPrice() const;
};


class GreenMail: public Mail {
	string type;  // "envelope", "bag", "box"
public:
	GreenMail(string send, string rec, string code, string t);
	int getPrice() const;
};

template <class T>
unsigned int numberDifferent(const vector<T> &v1){
	set<T> output;

	for(auto const &elem: v1) {
		output.insert(elem);
	}

	return output.size();
}

#endif /* SRC_MAIL_H_ */

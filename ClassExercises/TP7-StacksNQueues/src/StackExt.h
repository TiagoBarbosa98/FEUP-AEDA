# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
private:
	stack<T> defStack;
	stack<T> minStack;

public:
	StackExt() {};
	bool empty() const;
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

template <class T>
bool StackExt<T>::empty() const {
	defStack.empty();
	return true;
}

template <class T>
T& StackExt<T>::top() {
	return defStack.top();
}

template <class T>
void StackExt<T>::pop() {
	defStack.pop();
}

template <class T>
void StackExt<T>::push(const T& val) {
	defStack.push(val);
}


template <class T>
T& StackExt<T>::findMin() {

	stack<T>temp(defStack);
	T res = temp.top();
	temp.pop();

	while(!temp.empty()){
		if(temp.top() < res)
			res = temp.top();

		temp.pop();
	}

	return res;
}

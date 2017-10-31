/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
Filename: dlist.hpp
-----------------------------------------------------------------*/

template <typename T>
node<T>* dlist<T>::_createNode(T& d) {

	node<T>* n = new(node<T>)(d);

	return n;
}

template <typename T>
void dlist<T>::append(T& d) {

	node<T>* temp = _createNode(d);

	if (!_first) {

		_first = temp;
	}
	else {

		_last->_next = temp;
	}
	
	_last = temp;
}

template <typename T>
void dlist<T>::append1(T& d) {

	node<T>* temp = _createNode(d);

	node<T>* f = _first;
	node<T>* prev = nullptr;
	node<T>* end = nullptr;

	//Case for empty list
	if (!_first) {

		_first = temp;
		_first->_ptr = nullptr;
		_last = temp;
	}
	else {

		//Get the last but 1 node
		prev = (int)_last->_ptr ^ 0;
		_last->_ptr = prev ^ temp;
		temp->_ptr = _last ^ 0;

	}
}

//EOF


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

//EOF


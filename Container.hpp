#pragma once

template<class T>
class Container {
public:

	Container();  //constructor
	virtual ~Container();  //destructor
	Container & operator=(Container<T> &); //operator=
	Container(Container<T> &);  //copy constructor
	
	//element adding functions
	void putElementAtBegin( T );
	void putElementAtEnd( T );
	//                       value,position
	void putElementAtPostition( T, int );

	//element getting functions
	T getFirstElement();  //pop the first element
	T getLastElement();   //pop the last element
	T getElementsValueAt( int );  //get the Nth elements value

	//other functions
	bool isEmpty();  //check if the container is empty
	int getSize();   //gets the containers size
	void clear();    //clear the container

private:

	int c_size;  //containers size

	struct Element  //the node constructs container chain
	{					
		T e_value;
		Element * e_next;
		Element * e_previus;
		unsigned int e_number;
	};

	Element * c_First; //points to the first element
	Element * c_Last;  //points to the last element
};

#include "Container.hpp"
#include "includes.hpp"
#include "IBox.hpp"

template<class T>
Container<T>::Container()
{
	c_First = c_Last = nullptr;
	c_size = 0;
}

template<class T>
Container<T>::~Container()
{
	this->clear();
}

template<class T>
Container<T>::Container(Container & rhs)
{
	for (int i = 0; i < rhs.getSize(); ++i)
	{
		this->putElementAtEnd(rhs.getElementsValueAt(i));
	}
}

template<class T>
void Container<T>::putElementAtBegin( T valueToInsert )
{
	Element * toInsert = new Element;
	toInsert->e_value = valueToInsert;

	if (this->isEmpty())
	{
		toInsert->e_next = nullptr;
		toInsert->e_previus = nullptr;
		this->c_First = this->c_Last = toInsert;
		toInsert->e_number = c_size;
		c_size++;
	}
	else
	{
		Element * toCheck = new Element;
		toCheck = this->c_First;

		int counter;

		counter = this->getSize();

		while (counter != 0)
		{
			toCheck->e_number++;
			if (toCheck->e_next != nullptr)
			{
				toCheck = toCheck->e_next;
			}
			counter--;
		}

		this->c_First->e_previus = toInsert;
		toInsert->e_next = this->c_First;
		toInsert->e_previus = nullptr;
		this->c_First = toInsert;
		toInsert->e_number = 0;
		c_size++;


	}
}

template<class T>
void Container<T>::putElementAtEnd( T valueToInsert )
{
	Element * toInsert = new Element;
	toInsert->e_value = valueToInsert;

	if (this->isEmpty())
	{
		toInsert->e_next = nullptr;
		toInsert->e_previus = nullptr;
		this->c_First = this->c_Last = toInsert;
		toInsert->e_number = c_size;
		c_size++;
	}
	else
	{
		this->c_Last->e_next = toInsert;
		toInsert->e_previus = this->c_Last;
		toInsert->e_next = nullptr;
		this->c_Last = toInsert;
		toInsert->e_number = c_size;
		c_size++;
	}
}

template<class T>
T Container<T>::getFirstElement()
{
	T valueToReturn;

	if (this->isEmpty())
	{
		return 0;
	}
	else if (this->getSize() == 1)
	{
		valueToReturn = this->c_First->e_value;
		delete this->c_First;
		c_size--;
		return valueToReturn;
	}
	else
	{
		valueToReturn = this->c_First->e_value;
		this->c_First = this->c_First->e_next;
		delete this->c_First->e_previus;
		this->c_First->e_previus = nullptr;
		c_size--;
		return valueToReturn;
	}

}

template<class T>
T Container<T>::getLastElement()
{
	T valueToReturn;

	if (this->isEmpty())
	{
		return 0; //what to return
	}
	else if (this->getSize() == 1)
	{
		valueToReturn = this->c_Last->e_value;
		delete this->c_Last;
		c_size--;
		return valueToReturn;
	}
	else
	{
		valueToReturn = this->c_Last->e_value;
		this->c_Last = this->c_Last->e_previus;
		delete this->c_Last->e_next;
		this->c_Last->e_next = nullptr;
		c_size--;
		return valueToReturn;
	}
}

template<class T>
T Container<T>::getElementsValueAt(int position) //works like an iterator
{
	if (position > this->getSize()) //prevent to outside of container's size
	{
		position = this->getSize();
	}
	
	if (position == 0)
	{
		return this->c_First->e_value;
		//this->c_First = this->c_First->e_next; //error

	}
	else if (position == this->getSize())
	{
		return this->c_Last->e_value;
	}
	else {

		Element * checker = this->c_First;
		for (int i = 0; i < position; ++i)
		{
			checker = checker->e_next;
		}

		return checker->e_value;
	}

}

template<class T>
void Container<T>::putElementAtPostition(T valueToInsert, int position)
{
	if (this->isEmpty() || ( position == 0 ))
	{
		putElementAtBegin(valueToInsert);
	}
	else if ( position > this->getSize() || position == this->getSize())
	{
		putElementAtEnd(valueToInsert);
	}
	else
	{
		Element * toCheck = this->c_First;

		for (int i = 0; i < this->getSize(); ++i)
		{
			if ((int)toCheck->e_number != (int)position)
			{
				toCheck = toCheck->e_next;
			}
		}


		Element * toInsert = new Element;
		toCheck->e_previus->e_next = toInsert;
		toInsert->e_previus = toCheck->e_previus;
		toCheck->e_previus = toInsert;
		toInsert->e_next = toCheck;
		toInsert->e_value = valueToInsert;
		toInsert->e_number = toCheck->e_number - 1;
		c_size ++;


		int counter;

		counter = this->getSize() - (position + 1);

		while (counter != 0)
		{
			toCheck->e_number++;
			if (toCheck->e_next != nullptr)
			{
				toCheck = toCheck->e_next;
			}
			counter--;
		}
	}
}

template<class T>
Container<T> & Container<T>::operator=(Container & rhs)
{
	for (int i = 0; i < rhs.getSize(); ++i)
	{
		this->putElementAtEnd(rhs.getElementsValueAt(i));
	}

	return  *this;
}

template<class T>
bool Container<T>::isEmpty()
{
	if (this->getSize() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
int Container<T>::getSize()
{
	return c_size;
}

template<class T>
void Container<T>::clear()
{
	while (this->isEmpty() == false)
	{
		this->getLastElement();
	}
}

template class Container<int>;
template class Container<double>;
template class Container<float>;
template class Container<long>;
template class Container<long long>;
template class Container<char>;
template class Container<char*>;
template class Container<std::string>;
template class Container<Geometry::NBox *>; //because of NBox abstraction
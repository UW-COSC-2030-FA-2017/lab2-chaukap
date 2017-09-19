// ListProcessor.cpp
// tom bailey   1540  30 sep 2011
// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor and destructor.
// **Edited by Chandler Haukap 9/18/2017

#include "LinkedList.h"

int main()
{
	List cows;

	cout << "cows list  :  " << cows << endl << "And the size: " << cows.size() << endl;

	cows.insertAsLast(3.34); //testing insertAsLast method. 

	cows.insertAsLast(4.32);  //making sure it works twice in a row

	cows.insertAsLast(5.6);  //and again

	cows.insertAsFirst(1.23);

	cows.insertAsLast(8.5);  //beating a dead cow...

	cows.insertAsFirst(2.34);

	cout << "cows list  :  " << cows << endl << "And the size: " << cows.size() << endl << endl;



	cows.removeFirst();

	cout << "cows list  :  " << cows << endl << "And the size: " << cows.size() << endl << endl;


	List horses(cows);

	cout << "cows list  :  " << cows << endl;

	cout << "horses list:  " << horses << endl << "And the size: " << horses.size() << endl << endl;



	horses.removeFirst();

	horses.insertAsFirst(5.67);

	cows.insertAsFirst(6.78);

	cout << "cows list  :  " << cows << endl;

	cout << "horses list:  " << horses << endl << "And the size: " << horses.size() << endl << endl;



	List pigs;

	cout << "cows list  :  " << cows << endl;

	cout << "horses list:  " << horses << endl;

	cout << "pigs list  :  " << pigs << endl << "And the size: " << pigs.size() << endl << endl;



	pigs = cows;

	pigs.insertAsLast(7.777);

	cout << "cows list  :  " << cows << "  And the size: " << cows.size() << endl;

	cout << "horses list:  " << horses << "  And the size: " << horses.size() << endl;

	cout << "pigs list  :  " << pigs << "  And the size: " << pigs.size() << endl << endl;



	pigs = horses;

	cout << "cows list  :  " << cows << endl;

	cout << "horses list:  " << horses << endl;

	cout << "pigs list  :  " << pigs << endl << endl;



	cout << "End of code" << endl;



	return 0;

}
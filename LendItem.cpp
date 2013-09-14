// Bryan Wolfe

// Function definitions for the abstract class LendItem



#include <string>
#include <iostream>
#include "LendItem.h"

// default lenditem constructor
LendItem::LendItem( )
{
	setTitle( "Unknown" );
	setMedium( '?' );
	setBNumber( -1 );
	setBorrowed( false );
}

// lendItem constructor for user's defined values
LendItem::LendItem( string titl, char med )
{
	setTitle( titl );			//PRIVATE member variables
	setMedium( med );		 //		(‘B’ or ‘D’);
	setBNumber( -1 );
	setBorrowed( false );
}

// set methods
void LendItem::setTitle( string manu )
{
	title = manu;
}

void LendItem::setMedium( char med )
{
	mediumType = med;
}
void LendItem::setBNumber( int bNumber )
{
	borrowNumber = bNumber;
}
void LendItem::setBorrowed( bool bstatus )
{
	borrowed = bstatus;
}

// get methods
bool LendItem::getBorrowed( )
{
	return borrowed;
}
string LendItem::getTitle( )
{
	return title;
}
char LendItem::getMedium( )
{
	return mediumType;
}
int LendItem::getBNumber( )
{
	return borrowNumber;
}


// overloaded for output to the screen, same for every type derived from LendItem
ostream& operator<<( ostream& out, const LendItem& obj )
{

	if( obj.borrowed )
	{
		out << obj.title << " is currently borrowed." << endl
			<< "Borrower ID: " << obj.borrowNumber << endl; 
	}
	else
	{
		out << obj.title << " is currently available for rent." << endl;	
	}


	return out;
}


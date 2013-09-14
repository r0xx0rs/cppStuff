// Bryan Wolfe


// Function definitions for handling DVD rentals.


#include "DVD.h"



// calls LendItem constructor and sets DVD specific variables to defaults
DVD::DVD() : LendItem( "Unknown", 'D' )
{
	setRating( "Unknown" );

	setScreen('?');
}


// calls LendItem constructor and sets DVD specific variables to user's specifications
DVD::DVD( string titl, string rate, char stype )  : LendItem( titl, 'D' )
{

	setRating( rate );
	setScreen( stype );

}

// set methods
void DVD::setRating( string rate )
{
	rating = rate;
}

void DVD::setScreen( char type )
{
	screenType = type;
}

// get methods
string DVD::getRate()
{
	return rating;
}

char DVD::getType()
{
	return screenType;
}


// printAll realized for dvd specific values
void DVD::printAll( ostream& )
{
	cout << "Title: " << getTitle() << endl
		 << "Type: " << getMedium() << endl;
	if ( getBorrowed() )
		cout << "Available: Yes" << endl;
	else
		cout << "Available: No" << endl;

	cout << "Borrow Number: " << getBNumber() << endl
		 << "Rating: " << getRate() << endl
		 << "Screen Type: " << getType() << endl;


}
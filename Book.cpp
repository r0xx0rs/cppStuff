// Bryan Wolfe


// Function definitions for handling book rentals.


#include "Book.h"

// calls LendItem constructor and sets Book specific variables to defaults
Book::Book() : LendItem( "Unknown", 'B' )
{

	//author: string
	setAuthor( "Unknown" );
	//coverType: char   (‘S’or ‘H’)
	setCover( '?' );

}

// calls LendItem constructor and sets Book specific variables to user's specifications
Book::Book( string titl, string auth, char cover ) : LendItem( titl, 'B' )
{

	setAuthor( auth );
	setCover( cover );
}


// set methods
void Book::setAuthor( string auth )
{
	author = auth;
}

void Book::setCover( char type )
{
	coverType = type;
}

// get methods
string Book::getAuth()
{
	return author;
}

char Book::getCover()
{
	return coverType;
}


// printAll realized for book specific values
void Book::printAll( ostream& out )
{
	cout << "Title: " << getTitle() << endl
		 << "Type: " << getMedium() << endl;
	if ( getBorrowed() )
		cout << "Available: Yes" << endl;
	else
		cout << "Available: No" << endl;

	cout << "Borrow Number: " << getBNumber() << endl
		 << "Author: " << getAuth() << endl
		 << "Cover Type: " << getCover() << endl;
}



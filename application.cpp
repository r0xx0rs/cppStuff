// Bryan Wolfe


// Application file to allow the user to store books and DVD information


// includes all classes made for this application
#include "LendItem.h"
#include "DVD.h"
#include "Book.h"


// functions used to clean up switches.
Book enterBook();
DVD enterDVD();


int main()
{
	// max size to hold everything the user enters in 
	const int ARRAY_MAX = 40;
	// book and dvd arrays and integers to keep count
	Book books[ ARRAY_MAX ];
	int bookCount = 0;
	DVD dvds[ ARRAY_MAX ];
	int dvdCount = 0;

	// constants for switching
	const int ENTER_BOOK = 0, ENTER_DVD = 1, 
			  BORROW_BOOK = 2, BORROW_DVD = 3,
			  PRINT_BOOKS = 4, PRINT_DVDS = 5, 
			  IN_TITLE_OWNED_BORROW = 6, IN_TITLE_OUT_INFO = 7,
			  IN_AUTH_OUT_BOOKS = 8, ALL_BORROWED_NAMES = 9,
			  QUIT = 10;

	// user's choice for each iteration
	int choice;


	cout << "Welcome to the Marina Cafe's automated Book and DVD record keeping system." << endl;
	do
	{
		// prompts for a choice of operation
		cout << endl << "Please enter a number for choice of operation." << endl
			 << "0. to enter a new Book." << endl
			 << "1. to enter a new DVD." << endl
			 << "2. to borrow a Book by title." << endl
			 << "3. to borrow a  DVD by title." << endl 
			 << "4. to print out the title and borrowed status of all Books currently stored." << endl
			 << "5. to print out the title and borrowed status of all DVDs currently stored." << endl
			 << "6. to check availability of an item by title." << endl
			 << "7. to find all information about an item by title." << endl
			 << "8. to find all books by an Author." << endl
			 << "9. to output the names of all borrowed items." << endl
			 << "10. to quit the program." << endl;
		cin >> choice;// reads choice

		// switches on choice
		switch( choice )
		{
			// enter new Book
			case ENTER_BOOK:
				books[ bookCount ] = enterBook();
				bookCount++;
				break;


			// enter a new DVD
			case ENTER_DVD:
				dvds[ dvdCount ] = enterDVD();
				dvdCount++;
				break;


			// borrow a Book , user provides title of item to be borrowed 
			case BORROW_BOOK:
			{
				// book to find
				string bookTitle;
				// changes to true if found
				bool found = false;
				cout << "What is the title of the book you would like to borrow?" << endl;
				// used twice to allow for input to actually be read
				getline( cin, bookTitle );
				getline( cin, bookTitle );
				// goes through array to find a match
				for(int i = 0; i < bookCount; i++)
				{
					if(  bookTitle.compare( books[ i ].getTitle() ) == 0 )
					{
						// borrows the matched title
						books[ i ].setBorrowed( true );
						found = true;
					}
				}
				if( !found )
					cout << "Sorry, that book title was not found." << endl;
			}
			break;


			// borrow a  DVD, user provides title of item to be borrowed 
			case BORROW_DVD:
			{
				// dvd to find in array
				string dvdTitle;
				bool found = false;
				cout << "What is the title of the DVD you would like to borrow?" << endl;
				// used twice in order to read in a line
				getline( cin, dvdTitle );
				getline( cin, dvdTitle );
				// goes through array to find a match
				for(int i = 0; i < dvdCount; i++)
				{
					if(  dvdTitle.compare( dvds[ i ].getTitle() ) == 0 )
					{
						// borrows the matched title.
						dvds[ i ].setBorrowed( true );
						found = true;
					}
				}
				if( !found )
					cout << "Sorry, that DVD title was not found." << endl;
			}
			break;


			// print out the title and borrowed status of all Books currently stored  
			case PRINT_BOOKS:
				for( int i = 0; i < bookCount; i++ )
					cout << books[ i ];
				break;


			// print out the title and borrowed status of all DVDs currently stored 
			case PRINT_DVDS:
				for( int i = 0; i < dvdCount; i++ )
					cout << dvds[ i ];
				break;


			// accept a title as input, and output a message indicating if that item is owned by the marina, and if so, is available to borrow
			case IN_TITLE_OWNED_BORROW:
			{
				// book title to find
				string aTitle;
				bool found = false;
				cout << "What is the title of the book you would like to find?" << endl;
				// ensures line is read
				getline( cin, aTitle );
				getline( cin, aTitle );
				// goes through both arrays to find match
				for(int i = 0; i < bookCount; i++)
				{
					if(  aTitle.compare( books[ i ].getTitle() ) == 0 )
					{
						cout << aTitle << " is in our collection." << endl;
						if ( books[ i ].getBorrowed() )
							cout << aTitle << " is unavailable to borrow." << endl;
						else 
							cout << aTitle << " is available to borrow." << endl;
						found = true;
					}
				}
				for(int i = 0; i < dvdCount; i++)
				{
					if(  aTitle.compare( dvds[ i ].getTitle() ) == 0 )
					{
						cout << aTitle << " is in our collection." << endl;
						if ( dvds[ i ].getBorrowed() )
							cout << aTitle << " is unavailable to borrow." << endl;
						else 
							cout << aTitle << " is available to borrow." << endl;
						found = true;
					}
				}
				if( !found )
					cout << "Sorry, that title was not found." << endl;
			}
			break;


			// accept a title as input, and output all stored information about that title
			case IN_TITLE_OUT_INFO:
			{
				string aTitle;
				bool found = false;
				cout << "What is the title you would like information about?" << endl;
				// reads in twice to actual get a line of characters
				getline( cin, aTitle );
				getline( cin, aTitle );
				// searches for a match in both arrays and prints all information.
				for(int i = 0; i < dvdCount; i++)
				{
					if(  aTitle.compare( dvds[ i ].getTitle() ) == 0 )
					{
						dvds[ i ].printAll( cout );
						found = true;
					}
				}
				for(int i = 0; i < bookCount; i++)
				{
					if(  aTitle.compare( books[ i ].getTitle() ) == 0 )
					{
						books[ i ].printAll( cout );
						found = true;
					}
				}
				if( !found )
					cout << "Sorry, that title was not found." << endl;
			}
			break;
			// accept an author name as input, and output the title of all books by the author which are owned by the marina
			case IN_AUTH_OUT_BOOKS:
			{
				// author name to be found 
				string bookAuth;
				bool found = false;
				cout << "Who is the Author whose books you are trying to find?" << endl;
				// uses getline twice to actually read in a line of characters
				getline( cin, bookAuth );
				getline( cin, bookAuth );
				// searches for all books written by an author and prints their titles
				for(int i = 0; i < bookCount; i++)
				{
					if(  bookAuth.compare( books[ i ].getAuth() ) == 0 )
					{
						cout << "Title: " << books[ i ].getTitle() << endl;
						found = true;
					}
				}
				if( !found )
					cout << "Sorry, that author was not found." << endl;
			}
			break;

			// output the name only of all items which are currently owned but unavailable (ie have been borrowed) 
			case ALL_BORROWED_NAMES:
				// goes through both arrays and shows all items that have been borrowed
				for(int i = 0; i < bookCount; i++)
				{
					if(   books[ i ].getBorrowed()  )
					{
						cout << books[ i ].getTitle() << endl;
					}
				}
				for(int i = 0; i < dvdCount; i++)
				{
					if(   dvds[ i ].getBorrowed()  )
					{
						cout << dvds[ i ].getTitle() << endl;
					}
				}
				break;

			// Ends iteration of do-while and bids farewell
			case QUIT:
				cout << "Goodbye!"<< endl;
				break;
			// default in case the choice was not valid.
			default:
				cout << "That is not a valid choice." << endl;
				break;


		}
	}while( choice!= QUIT ); // QUIT value ends program


	return 0; // ends main
}


// reads in and creates new book object
Book enterBook()
{
	// variables to create book objects
	string bookTitle, authorName;
	char coverType;
	cout << "Please enter Book Title." << endl;
	// used twice or else I can't read first line of input
	getline( cin, bookTitle);
	getline( cin, bookTitle); 
	
	cout << "Please enter the Author's Name." << endl;
	getline( cin, authorName );
	cout << "Please enter Cover Type, S for Softcover, or H for Hardcover." << endl;
	cin >> coverType;

	// returns created book object
	return Book( bookTitle, authorName, coverType );	
}

// reads in and creates new dvd object
DVD enterDVD()
{
	// variables to create book objects
	string dvdTitle, dvdRating;
	char screenType;
	cout << "Please enter DVD Title." << endl;
	// used twice or else I can't read first line of input
	getline( cin, dvdTitle );
	getline( cin, dvdTitle );

	cout << "Please enter the DVD's rating." << endl;
	getline( cin, dvdRating );
	cout << "Please enter the Screen Type, W for Widescreen, or F for Fullscreen." << endl;
	cin >> screenType;

	// returns created DVD object.
	return DVD( dvdTitle, dvdRating, screenType );
}
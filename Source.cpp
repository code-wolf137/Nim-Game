/*
Anthony Salerno - CSCI 105
NIM Game Project
*/

#include <iostream> //cin and cout
#include <string> //string variables
#include <conio.h> //system("cls") and _getch()

using namespace std;

//function prototypes

void changeSettings(int &n, int &m, string &turn, string &finalTurn, string &cpu); 

void playGame(int n, int m, string turn, string finalTurn, string cpu);		//initializng function for playing

void playEasy(int n, int m, string turn, string finalTurn, string cpu);		//easy mode

void playExpert(int n, int m, string turn, string finalTurn, string cpu);	//expert mode

void playTutor(int n, int m, string turn, string finalTurn, string cpu);	//tutor mode

int main()
{
	int n = 25, m = 3, x; //n and m are default values for NIM game rules
	bool Q = true; //Q is a boolean variable that keeps the do-while loop running while it is true
	string turn = "PLAYER", finalTurn = "WINNER", cpu = "EASY"; //default string variables

	do //do-while loop runs at least once until the given condition returns as false
	{
		/*system("cls");*/
		//display of default settings for the NIM game
		cout << "*************************************************************************" << endl;
		cout << "*\tThe current settings for this game are : \t\t\t*" << endl;
		cout << "*\ta\t n = " << n << "(number of coins the game starts with)\t\t*" << endl;
		cout << "*\tb\t m = " << m << "(max number of coins that can be taken per turn)\t*" << endl;
		cout << "*\tc\t First turn : " << turn << "\t\t\t\t\t*" << endl;
		cout << "*\td\t Player that takes the last coin : " << finalTurn << "\t\t*" << endl;
		cout << "*\te\t CPU mode : " << cpu << "\t\t\t\t\t*" << endl;
		cout << "*\tf\t Return to previous menu\t\t\t\t*" << endl;
		cout << "*************************************************************************" << endl << endl << endl;


		//Options for the user to choose
		cout << "*****************************************************************" << endl;
		cout << "*\t a : Play the game with the current settings\t\t*" << endl;
		cout << "*\t b : Change the settings of the game\t\t\t*" << endl;
		cout << "*\t c : Quit the game\t\t\t\t\t*" << endl;
		cout << "*****************************************************************" << endl << endl;
		cout << "Input the letter you would like to choose : ";
		x = _getch(); //input is ASCI code of character entered

		system("cls"); //clears screen
		
		//switch has 3 different paths and the default depending on the input of x
		switch (x) //switch matches to the ASCI of the inputted values
		{
				case static_cast<char>('A') :

				case static_cast<char>('a') : playGame(n, m, turn, finalTurn, cpu); break; //if option A, game starts by calling playGame function

				case static_cast<char>('B') :

				case static_cast<char>('b') : changeSettings(n, m, turn, finalTurn, cpu); break; //calls the changeSettings function

				case static_cast<char>('C') :
				
				case static_cast<char>('c') : Q = false; break; //changes Q to zero or false which breaks the loop and ends the program

				default: system("cls"); //clears screen and puts error message on top
					cout << "That is not a valid input.  Please input the number of the option you would like to choose." << endl << endl; break; //if other input
		}
	} while (Q); //testing whether Q is true or false to see when to end the loop
	return 0; //end of main function
}

//variables used with the & will change their value in the main function
void changeSettings(int &n, int &m, string &turn, string &finalTurn, string &cpu) //function definition
{
	int x, temp; //x is integer for inputs
	bool Q = true; //functions same as other Q variable

	do
	{
		//Display the current settings and the option to choose what to change
		cout << "*************************************************************************" << endl;
		cout << "*\tThe current settings for this game are : \t\t\t*" << endl;
		cout << "*\ta\t n = " << n << "(number of coins the game starts with)\t\t*" << endl;
		cout << "*\tb\t m = " << m << "(max number of coins that can be taken per turn)\t*" << endl;
		cout << "*\tc\t First turn : " << turn << "\t\t\t\t\t*" << endl;
		cout << "*\td\t Player that takes the last coin : " << finalTurn << "\t\t*" << endl;
		cout << "*\te\t CPU mode : " << cpu << "\t\t\t\t\t*" << endl;
		cout << "*\tf\t Return to previous menu\t\t\t\t*" << endl;
		cout << "*************************************************************************" << endl << endl << endl;
		cout << "Enter the letter of the option you would like to change : ";
		x = _getch();


		switch (x) //cases based on ASCI code of input x
		{
			case static_cast<char>('A'):
			case static_cast<char>('a'):	cout<<"\nPlease enter a new number of starting coins (between 1 and 99) : ";
											cin >> temp; //new n value
											if (temp > 0 && temp <= 99) //implementing input validation for n
												n = temp;
											else
											{
												cout << "Invalid input." << endl;
												system("pause");
											}
											system("cls");
											break;
			case static_cast<char>('B'):
			case static_cast<char>('b'):	cout<<"\nPlease enter a new number of maximum number of coins taken per turn (between 1 and " << (n - 1) << ") :";
											cin >> temp; //new m value
											if (temp > 0 && temp < n) //implementing input validation for m
												m = temp;
											else
											{
												cout << "Invalid input.  Please input a positive integer." << endl;
												system("pause");
											}
											system("cls");
											break;
			case static_cast<char>('C'):
			case static_cast<char>('c'):	if (turn == "PLAYER") //changes to CPU
												turn = "CPU";
											else //if anything else, just CPU, changes back to player
												turn = "PLAYER";		
											system("cls");
											break;
			case static_cast<char>('D'):
			case static_cast<char>('d'):	if (finalTurn == "WINNER") //changes to loser
												finalTurn = "LOSER";
											else
												finalTurn = "WINNER"; //chanegs to winner
											system("cls"); 
											break;
			case static_cast<char>('E'):
			case static_cast<char>('e'):	if (cpu == "EASY") //cycles through easy to expert to tutor back to easy and so on
												cpu = "EXPERT";
											else if (cpu == "EXPERT")
												cpu = "TUTOR";
											else
												cpu = "EASY";
											system("cls");
											break;
			case static_cast<char>('F'):
			case static_cast<char>('f'):	system("cls");
											break; //case f closes loop

			default: system("cls");
				cout << "\nThat is not a valid input.  Please input the letter of the option you would like to choose." << endl << endl; break;

		}
	} while ((x != static_cast<char>('F')) && (x != static_cast<char>('f'))); //when case f chosen, function breaks and returns to previous loop
}

void playEasy(int n, int m, string turn, string finalTurn, string cpu) //easy mode
{
	int k; //integer for amount of coins to take

	//Display the current settings during gameplay
	cout << "*************************************************************************" << endl;
	cout << "*\tThe current settings for this game are : \t\t\t*" << endl;
	cout << "*\ta\t n = " << n << "(number of coins the game starts with)\t\t*" << endl;
	cout << "*\tb\t m = " << m << "(max number of coins that can be taken per turn)\t*" << endl;
	cout << "*\tc\t First turn : " << turn << "\t\t\t\t\t*" << endl;
	cout << "*\td\t Player that takes the last coin : " << finalTurn << "\t\t*" << endl;
	cout << "*\te\t CPU mode : " << cpu << "\t\t\t\t\t*" << endl;
	cout << "*\tf\t Return to previous menu\t\t\t\t*" << endl;
	cout << "*************************************************************************" << endl << endl << endl;

	while (n > 0) //while n is greater than 0 but not 0
	{
		if (turn == "PLAYER") //if it is player's turn
		{
			cout << "Remaining coins : " << n << endl; //displays remaining coins
			cout << "Please enter the number of coins you would like to take : "; //prompt
			cin >> k;
			
			if (k > 0 && k <= m && k <= n) //k must be positive, less than or equal to limit m, and less than or equal to n so that n will never be negative
			{
				n -= k; //subtracts k from n
				cout << "Remaining coins : " << n << endl; //displays remaining coins
				turn = "CPU"; //changes turn to CPU
			}
			else
			{
				if (m < n)
					cout << "Invalid input.  Please enter an integer greater than 0 and less than or equal to " << m << endl; //invaid input prompt
				else if (m > n)
					cout << "Invalid input.  Please enter an integer greater than 0 and less than or equal to " << n << endl;
			}
		}
		else if (turn == "CPU") //if CPU's turn
		{
			k = rand() % (m + 1); //generates random number for k between 1 and m
			if (k > 0 && k <= n) //continues if k is positive and less than or equal to n
			{
				n -= k;
				turn = "PLAYER"; //changes turn to player
				cout << "The CPU took " << k << " coins.  Your move." << endl; //displays number of coins taken by CPU
			}
		}
	}
	if (n == 0) //once there are no coins left, determining winner
	{
		if (finalTurn == "WINNER") //final turn is winner
		{
			if (turn == "PLAYER") //since turn is set to PLAYER, CPU took the last turn so CPU wins
				cout << "Sorry, the CPU is the winner." << endl;
			else if (turn == "CPU") //PLAYER took last turn to PLAYER wins
				cout << "Congratulations! You win!" << endl;
		}
		else if (finalTurn == "LOSER") //final turn is loser
		{
			if (turn == "PLAYER") //CPU took last turn so player is winner
				cout << "Congratulations! You win!" << endl;
			else if (turn == "CPU") //PLAYER took last turn so CPU is winner
				cout << "Sorry, the CPU is the winner." << endl;
		}
		system("pause"); //pause until button pressed
		system("cls"); //clears game screen then function closes and returns to menu
	}
}

//the core of this exepert mode is the same as the easy mode so i am not going to make all the same comments again
//the same goes for tutor mode, but i'll comment what is different

void playExpert(int n, int m, string turn, string finalTurn, string cpu) //expert mode
{
	int k;

	//Display the current settings
	cout << "*************************************************************************" << endl;
	cout << "*\tThe current settings for this game are : \t\t\t*" << endl;
	cout << "*\ta\t n = " << n << "(number of coins the game starts with)\t\t*" << endl;
	cout << "*\tb\t m = " << m << "(max number of coins that can be taken per turn)\t*" << endl;
	cout << "*\tc\t First turn : " << turn << "\t\t\t\t\t*" << endl;
	cout << "*\td\t Player that takes the last coin : " << finalTurn << "\t\t*" << endl;
	cout << "*\te\t CPU mode : " << cpu << "\t\t\t\t\t*" << endl;
	cout << "*\tf\t Return to previous menu\t\t\t\t*" << endl;
	cout << "*************************************************************************" << endl << endl << endl;

	while (n > 0)
	{
		if (turn == "PLAYER")
		{
			cout << "Remaining coins : " << n << endl;
			cout << "Please enter the number of coins you would like to take : ";
			cin >> k;

			if (k > 0 && k <= m && k <= n) //if k is an acceptable value, play continues
			{
				n -= k;
				cout << "Remaining coins : " << n << endl; //displays remaining coins
				turn = "CPU"; //turn chanegs to cpu
			}
			else
			{
				if (m < n)
					cout << "Invalid input.  Please enter an integer greater than 0 and less than or equal to " << m << endl; //invaid input prompt
				else if (m > n)
					cout << "Invalid input.  Please enter an integer greater than 0 and less than or equal to " << n << endl;
			}
		}
		else if (turn == "CPU")
		{
			if (finalTurn == "WINNER")
			{
				k = rand() % (m + 1); //random k
				if (k > 0 && k <= n)
				{
					if ((n % (m + 1)) != 0) //computer in winning state so good move possible since n is not divisible by (m + 1)
					{
						if ((n - k) % (m + 1) == 0) //if k is optimal which keeps CPU in winning state move take that number, otherwise loop repeats until this holds true
						{
							n -= k;
							turn = "PLAYER";
							cout << "The CPU took " << k << " coins.  Your move." << endl;
						}
					}
					else if ((n % (m + 1)) == 0) //computer in losing state so no good move
					{
						n -= k; //takes random number of coins bc no good move exists
						turn = "PLAYER";
						cout << "The CPU took " << k << " coins.  Your move." << endl;
					}
				}
			}
			else if (finalTurn == "LOSER")
			{
				k = rand() % (m + 1);
				if (k > 0 && k <= n)
				{
					if (((n - 1) % (m + 1)) != 0) //computer in winning state so good move possible
					{
						if ((n - k - 1) % (m + 1) == 0) //if k is optimal move take that number, otherwise loop repeats until this holds true
						{
							n -= k;
							turn = "PLAYER";
							cout << "The CPU took " << k << " coins.  Your move." << endl;
						}
					}
					else if (((n - 1) % (m + 1)) == 0) //computer in losing state so no good move
					{
						n -= k; //takes random number of coins bc no good move exists
						turn = "PLAYER";
						cout << "The CPU took " << k << " coins.  Your move." << endl;
					}
				}
			}
		}
	}
	if (n == 0) //determines winner once coins are gone
	{
		if (finalTurn == "WINNER")
		{
			if (turn == "PLAYER")
				cout << "Sorry, the CPU is the winner." << endl;
			else if (turn == "CPU")
				cout << "Congratulations! You win!" << endl;
		}
		else if (finalTurn == "LOSER")
		{
			if (turn == "PLAYER")
				cout << "Congratulations! You win!" << endl;
			else if (turn == "CPU")
				cout << "Sorry, the CPU is the winner." << endl;
		}
		system("pause");
		system("cls");
	}
}

void playTutor(int n, int m, string turn, string finalTurn, string cpu) //tutor mode
{
	int k;

	//Display the current settings 
	cout << "*************************************************************************" << endl;
	cout << "*\tThe current settings for this game are : \t\t\t*" << endl;
	cout << "*\ta\t n = " << n << "(number of coins the game starts with)\t\t*" << endl;
	cout << "*\tb\t m = " << m << "(max number of coins that can be taken per turn)\t*" << endl;
	cout << "*\tc\t First turn : " << turn << "\t\t\t\t\t*" << endl;
	cout << "*\td\t Player that takes the last coin : " << finalTurn << "\t\t*" << endl;
	cout << "*\te\t CPU mode : " << cpu << "\t\t\t\t\t*" << endl;
	cout << "*\tf\t Return to previous menu\t\t\t\t*" << endl;
	cout << "*************************************************************************" << endl << endl << endl;

	while (n > 0)
	{
		if (turn == "PLAYER")
		{
			cout << "Remaining coins : " << n << endl;
			cout << "Please enter the number of coins you would like to take : ";
			cin >> k;

			if (k > 0 && k <= m && k <= n)
			{
				if (finalTurn == "WINNER")
				{
					if ((n % (m + 1)) != 0) //player is in winning state so good move possible
					{
						if ((n - k) % (m + 1) == 0) //if k is optimal move, the cpu allows player to make that move.  The move cannot be made until it is optimal
						{
							n -= k;
							cout << "Remaining coins : " << n << endl; //displays remaining coins
							turn = "CPU";
						}
						else //if k is not an optimal move, cpu asks if you are sure and you enter number again and loos back for new input
							cout << "Are you sure you want to take " << k << " coins?" << endl;
					}
					else if ((n % (m + 1)) == 0) //player in losing state so no good move but computer will put itself in losing state next round to help
					{
						n -= k;
						turn = "CPU";
					}
				}
				else if (finalTurn == "LOSER")
				{
					if (k > 0 && k <= n)
					{
						if (((n - 1) % (m + 1)) != 0) //player in winning state so good move possible
						{
							if ((n - k - 1) % (m + 1) == 0) //if k is optimal move take that number, otherwise loop repeats until this holds true
							{
								n -= k;
								turn = "CPU";
							}
							else
								cout << "Are you sure you want to take " << k << " coins?" << endl;
						}
						else if (((n - 1) % (m + 1)) == 0) //player in losing state so no good move
						{
							n -= k; //takes original number of coins bc no good move exists
							turn = "CPU";
						}
					}
				}
			}
			else
			{
				if (m < n)
					cout << "Invalid input.  Please enter an integer greater than 0 and less than or equal to " << m << endl; //invaid input prompt
				else if (m > n)
					cout << "Invalid input.  Please enter an integer greater than 0 and less than or equal to " << n << endl;
			}
		}
		else if (turn == "CPU")
		{
			if (finalTurn == "WINNER")
			{
				k = rand() % (m + 1);
				if (k > 0 && k <= n)
				{
					if ((n % (m + 1)) != 0) //computer in winning state so needs to move to losing state
					{
						if ((n - k) % (m + 1) != 0) //if k is NOT optimal move take that number to move into losing state
						{							//loop repeats until randomely generated number satisfies this criteria
							n -= k;
							turn = "PLAYER";
							cout << "The CPU took " << k << " coins.  Your move." << endl;
						}
					}
					else if ((n % (m + 1)) == 0) //computer in losing state so no good move so random number will work
					{
						n -= k; //takes random number of coins bc no good move exists
						turn = "PLAYER";
						cout << "The CPU took " << k << " coins.  Your move." << endl;
					}
				}
			}
			else if (finalTurn == "LOSER")
			{
				k = rand() % (m + 1);
				if (k > 0 && k <= n)
				{
					if (((n - 1) % (m + 1)) != 0) //computer in winning state so need to move to losing state
					{
						if ((n - k - 1) % (m + 1) != 0) //if k is NOT optimal move take that number, otherwise loop repeats until this holds true
						{
							n -= k;
							turn = "PLAYER";
							cout << "The CPU took " << k << " coins.  Your move." << endl;
						}
					}
					else if (((n - 1) % (m + 1)) == 0) //computer in losing state so no good move
					{
						n -= k; //takes random number of coins bc no good move exists
						turn = "PLAYER";
						cout << "The CPU took " << k << " coins.  Your move." << endl;
					}
				}
			}
		}
	}
	if (n == 0)
	{
		if (finalTurn == "WINNER")
		{
			if (turn == "PLAYER")
				cout << "Sorry, the CPU is the winner." << endl;
			else if (turn == "CPU")
				cout << "Congratulations! You win!" << endl;
		}
		else if (finalTurn == "LOSER")
		{
			if (turn == "PLAYER")
				cout << "Congratulations! You win!" << endl;
			else if (turn == "CPU")
				cout << "Sorry, the CPU is the winner." << endl;
		}
		system("pause");
		system("cls");
	}
}

void playGame(int n, int m, string turn, string finalTurn, string cpu) //playGame funcion that starts game
{
	//criteria determines which mode to play and calls the corresponding function
	if (cpu == "EASY")
		playEasy(n, m, turn, finalTurn, cpu);
	else if (cpu == "EXPERT")
		playExpert(n, m, turn, finalTurn, cpu);
	else if (cpu == "TUTOR")
		playTutor(n, m, turn, finalTurn, cpu);
}
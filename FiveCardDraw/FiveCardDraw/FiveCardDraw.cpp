#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

enum Ranks { Clubs, Diamonds, Hearts, Spades };
enum Suits { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

void dealCard(int hand[][5], int loc);
void dealHand(int hand[][5], int num);
void swapCards(int hand[][5], int num);
void convertToInt(string hand[], int numHand[2][5]);
string findWinner(int hand[][5], int num, int& score);
string getRank(Ranks rank);
string getSuit(Suits suit);
void CardArt(string cardValue[5]);
void printHand(int hand[][5], int num);

int main()
{
	int score = 0;
	srand(time(NULL));
	int option = 0;
	int hand[2][5];
	bool stop = false;

	while (stop != true)
	{
		cout << "****************" << endl;
		cout << "Five Card Draw" << endl;
		cout << "****************" << endl << endl;
		cout << "1. Play" << endl;
		cout << "2. Exit" << endl << endl;
		cout << "Choose your option: ";
		cin >> option;

		if (option != 2) {
			string strHand[5] = { "", "", "", "", "" };

			cout << "\nYour score is " << score << endl;
			dealHand(hand, 2);
			printHand(hand, 2);

			char yesOrNo;
			cout << endl << endl << "Do you want to change cards? (y/n): ";
			cin >> yesOrNo;
			if (yesOrNo == 'y') {
				swapCards(hand, 2);
				cout << endl << "Your new cards are:" << endl;
				printHand(hand, 2);
				cout << endl;
			}

			cout << endl << findWinner(hand, 2, score) << endl;
			cin.ignore(256, '\n');
			cout << "\nYour score is " << score << endl;
			if (score < -9)
			{
				cout << "\nGame over" << endl;
				stop = true;
			}
			if (score > 9)
			{
				cout << "\nYou win" << endl;
				score = 0;
			}
			cout << endl << "Hit return to continue...";
			cin.get();
			cout << "\n\n";
		}
		else {
			stop = true;
		}
	}
	return 0;
}

void dealCard(int hand[][5], int loc)
{
	int card;
	bool duplicate = false;
	bool valid = false;
	int randNum;
	Ranks aRank;
	Suits aSuit;

	while (valid == false)
	{
		randNum = (rand() % 13) + 1;
		aRank = Ranks(randNum);
		randNum = rand() % 4;
		aSuit = Suits(randNum);
		duplicate = false;
		for (int c = 0; c < 5; ++c)
		{
			if (hand[0][c] == aRank && hand[1][c] == aSuit)
			{
				duplicate = true;
			}
		}

		if (duplicate == false)
		{
			valid = true;
		}
	}

	hand[0][loc] = aRank;
	hand[1][loc] = aSuit;
}

void CardArt(string cardValue[5])
{
	string aCard[7][40] = { {" ","_","_","_","_","_"," "," "," ","_","_","_","_","_"," "," "," ","_","_","_","_","_"," "," "," ","_","_","_","_","_"," "," "," ","_","_","_","_","_"," "," "},
				{"|"," "," "," ","R","U","|"," ","|"," "," "," ","F","W","|"," ","|"," "," "," ","V","Z","|"," ","|"," "," "," ","X","L","|"," ","|"," "," "," ","O","N","|"," "},
				{"|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," "},
				{"|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," "},
				{"|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," ","|"," "," "," "," "," ","|"," "},
				{"|","R","U","_","_","_","|"," ","|","F","W","_","_","_","|"," ","|","V","Z","_","_","_","|"," ","|","X","L","_","_","_","|"," ","|","O","N","_","_","_","|"," "},
				{" "," "," ","1"," "," "," "," "," "," "," ","2"," "," "," "," "," "," "," ","3"," "," "," "," "," "," "," ","4"," "," "," "," "," "," "," ","5"," "," "," "," "} };


	for (int r = 0; r < 7; r++)
	{
		for (int c = 0; c < 40; c++)
		{
			if (aCard[r][c] == "R")
			{
				aCard[r][c] = cardValue[0].substr(0, 1);
			}
			else if (aCard[r][c] == "U")
			{
				aCard[r][c] = cardValue[0].substr(1, 1);
			}
			else if (aCard[r][c] == "F")
			{
				aCard[r][c] = cardValue[1].substr(0, 1);
			}
			else if (aCard[r][c] == "W")
			{
				aCard[r][c] = cardValue[1].substr(1, 1);
			}
			else if (aCard[r][c] == "V")
			{
				aCard[r][c] = cardValue[2].substr(0, 1);
			}
			else if (aCard[r][c] == "Z")
			{
				aCard[r][c] = cardValue[2].substr(1, 1);
			}
			else if (aCard[r][c] == "X")
			{
				aCard[r][c] = cardValue[3].substr(0, 1);
			}
			else if (aCard[r][c] == "L")
			{
				aCard[r][c] = cardValue[3].substr(1, 1);
			}
			else if (aCard[r][c] == "O")
			{
				aCard[r][c] = cardValue[4].substr(0, 1);
			}
			else if (aCard[r][c] == "N")
			{
				aCard[r][c] = cardValue[4].substr(1, 1);
			}
			cout << aCard[r][c];
		}
		cout << endl;
	}
}

void dealHand(int hand[][5], int num)
{
	for (int i = 0; i < 5; ++i)
	{
		dealCard(hand, i);
	}
}

void swapCards(int hand[][5], int num)
{
	char yesOrNo;

	for (int i = 0; i < 5; i++) {
		cout << "Change card " << (i + 1) << "? (y/n): ";
		cin.ignore(256, '\n');
		cin >> yesOrNo;

		if (yesOrNo == 'y') {
			dealCard(hand, i);
		}
		else {
			continue;
		}
	}
}

void convertToInt(string hand[], int numHand[2][5])
{
	stringstream stream;

	for (int i = 0; i < 5; i++) {
		if (hand[i].substr(0, 2) == "10") {
			numHand[0][i] = 10;
		}
		else if (hand[i].substr(0, 1) == "A") {
			numHand[0][i] = 1;
		}
		else if (hand[i].substr(0, 1) == "J") {
			numHand[0][i] = 11;
		}
		else if (hand[i].substr(0, 1) == "Q") {
			numHand[0][i] = 12;
		}
		else if (hand[i].substr(0, 1) == "K") {
			numHand[0][i] = 13;
		}
		else {
			stream << hand[i].substr(0, 1);
			stream >> numHand[0][i];
			stream.str("");
			stream.clear();
		}
	}
}

string findWinner(int hand[][5], int num, int& score)
{
	string result = "Sorry, better luck next time!";

	bool straightFlush = false;
	bool fourOfAKind = false;
	bool fullHouse = false;
	bool flush = false;
	bool straight = false;
	bool threeOfAKind = false;
	bool twoPair = false;
	bool onePair = false;

	enum {
		PAIR = 1,
		TWO_PAIR,
		THREE_OF_A_KIND,
		FULL_HOUSE,
		FLUSH,
		FOUR_OF_A_KIND = 6
	};

	int cards[2][5];

	vector<int> winners(0);
	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 4; j++) {
			if (hand[0][i] == hand[0][j + 1])
				winners.push_back(hand[0][i]);
		}
	}

	if (winners.size() == FOUR_OF_A_KIND)
		fourOfAKind = true;
	else if (winners.size() == FLUSH)
		flush = true;
	else if (winners.size() == FULL_HOUSE)
		fullHouse = true;
	else if (winners.size() == THREE_OF_A_KIND)
		threeOfAKind = true;
	else if (winners.size() == TWO_PAIR)
		twoPair = true;
	else if (winners.size() == PAIR)
		onePair = true;

	vector<int> orderCards(0);
	for (int i = 0; i < 5; i++)
		orderCards.push_back(hand[0][i]);

	bool swapped = true;
	int j = 0;
	int tmp;

	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < (orderCards.size() - j); i++) {
			if (orderCards[i] > orderCards[i + 1]) {
				tmp = orderCards[i];
				orderCards[i] = orderCards[i + 1];
				orderCards[i + 1] = tmp;
				swapped = true;
			}
		}
	}
	int checkStraight = orderCards.back();

	while (checkStraight != orderCards.front()) {
		checkStraight--;
	}

	if (checkStraight == (orderCards.back() - (orderCards.size() - 1))) {
		straight = true;
	}
	else if ((orderCards[0] == 1) &&
		(orderCards[1] == 10) &&
		(orderCards[2] == 11) &&
		(orderCards[3] == 12) &&
		(orderCards[4] == 13)) {
		straight = true;
	}

	for (int i = 0; i < 4; i++) {
		if (hand[1][i] == hand[1][i + 1]) {
			flush = true;
		}
		else {
			flush = false;
			break;
		}
	}

	if ((straight == true) && (flush == true))
	{
		straightFlush = true;
	}
	if (straightFlush == true)
	{
		result = "You have a Straight Flush!";
		score += 8;
	}

	else if (fourOfAKind == true)
	{
		result = "You have a Four Of A Kind!";
		score += 7;
	}
	else if (fullHouse == true)
	{
		result = "You have a Full House!";
		score += 6;
	}
	else if (flush == true)
	{
		result = "You have a Flush!";
		score += 5;
	}
	else if (straight == true)
	{
		result = "You have a Straight!";
		score += 4;
	}
	else if (threeOfAKind == true)
	{
		result = "You have a Three Of A Kind!";
		score += 3;
	}
	else if (twoPair == true)
	{
		result = "You have a Two Pair!";
		score += 2;
	}
	else if (onePair == true)
	{
		result = "You have a Pair!";
		score += 1;
	}
	else
	{
		score -= 1;
	}

	return result;
}

string getRank(Ranks rank)
{
	switch (rank)
	{
	case Ace:
		return "A";
	case Two:
		return "2";
	case Three:
		return "3";
	case Four:
		return "4";
	case Five:
		return "5";
	case Six:
		return "6";
	case Seven:
		return "7";
	case Eight:
		return "8";
	case Nine:
		return "9";
	case Ten:
		return "T";
	case Jack:
		return "J";
	case Queen:
		return "Q";
	case King:
		return "K";
	default:
		break;
	}
}

string getSuit(Suits suit)
{
	switch (suit)
	{
	case Clubs:
		return "C";
	case Diamonds:
		return "D";
	case Hearts:
		return "H";
	case Spades:
		return "S";
	default:
		break;
	}
}

void printHand(int hand[][5], int num)
{
	string cardValue[5];
	for (int c = 0; c < 5; ++c)
	{
		switch (hand[0][c])
		{
		case Ace:
			cardValue[c] = "A";
			break;
		case Two:
			cardValue[c] = "2";
			break;
		case Three:
			cardValue[c] = "3";
			break;
		case Four:
			cardValue[c] = "4";
			break;
		case Five:
			cardValue[c] = "5";
			break;
		case Six:
			cardValue[c] = "6";
			break;
		case Seven:
			cardValue[c] = "7";
			break;
		case Eight:
			cardValue[c] = "8";
			break;
		case Nine:
			cardValue[c] = "9";
			break;
		case Ten:
			cardValue[c] = "T";
			break;
		case Jack:
			cardValue[c] = "J";
			break;
		case Queen:
			cardValue[c] = "Q";
			break;
		case King:;
			cardValue[c] = "K";
			break;
		default:
			break;
		}

		switch (hand[1][c])
		{
		case Clubs:
			cardValue[c] += "C";
			break;
		case Diamonds:
			cardValue[c] += "D";
			break;
		case Hearts:
			cardValue[c] += "H";
			break;
		case Spades:
			cardValue[c] += "S";
			break;
		default:
			break;
		}
		cout << endl;
	}
	CardArt(cardValue);
}
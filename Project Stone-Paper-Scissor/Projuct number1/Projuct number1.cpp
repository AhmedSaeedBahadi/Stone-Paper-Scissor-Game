//My solve
  /* #include<iostream>
#include<cstdlib>
using namespace std;
enum EnChoice { Paper = 1, Stone = 2,Scissors };
int ReadNum(string Massage)
{
	int Num = 0;
	do
	{
		cout << Massage << endl;
		cin >> Num;
	} while (1 > Num||Num>10);
	
	return Num;
}
EnChoice GetUserChoise(int NumOfRaound,int NumOfRound)
{
	
		EnChoice Choise;
		int Num = 0;
		do
		{
			cout << "Round[" << NumOfRound << "] begins:\n";
			cout << "Your choise :[1] :Paper,[2]:Stone,[3]:Scissors\n";
			cin >> Num;
		} while (Num<1||Num>3);
		
		return Choise = EnChoice(Num);
	
}
int RandomNum(int From, int To)
{
	int Rand = 0;
	Rand = rand() % (To - From + 1) + From;
	return Rand;
}
EnChoice ChoiseComputer()
{
	int ComputerChoise = 0;
	EnChoice EnComputerChoise;
	ComputerChoise = RandomNum(1, 3);
	return  EnComputerChoise = EnChoice(ComputerChoise);
}
void PlayRound(int NumOfRaound, int& ComputerOwnTimes, int& UserWonTimes, int& DrawTimes)
{
	for (int i = 1;i <= NumOfRaound;i++)
	{
		EnChoice UserChoice = GetUserChoise(NumOfRaound, i);
		EnChoice ComputerChoice = ChoiseComputer();
		if (UserChoice == ComputerChoice)
		{
			cout << "______________________Round[" << i << "]_________________________\t\n";
			cout << "Player choice: " ;
			if (UserChoice == 1)
			{
				cout << "Paper" << endl;
			}
			else if (UserChoice == 2)
			{
				cout << "Stone\n";
			}
			else
			{
				cout << "Scisser\n";
			}
			cout << "Computer choice: ";
			if (ComputerChoice == 1)
			{
				cout << "Paper" << endl;
			}
			else if (ComputerChoice == 2)
			{
				cout << "Stone\n";
			}
			else
			{
				cout << "Scisser\n";
			}
			cout << "Round Winner:" << "[No winner]" << endl;
			system("color 6F");
			cout << "\a";
			cout << "___________________________________________________________________\t\t\n";
			DrawTimes++;
		}
		else if (UserChoice == EnChoice::Scissors && ComputerChoice == EnChoice::Stone)
		{
			cout << "______________________Round[" << i << "]_________________________\t\n";
			cout << "Player choice: Scissors " << endl;
			cout << "Computer choice: Stone " << endl;
			cout << "Round Winner:" << "[Computer] " << endl;
			system("color 4F");
			cout << "\a";
			cout << "___________________________________________________________________\t\t\n";
			ComputerOwnTimes++;

		}
		else if (UserChoice == EnChoice::Scissors && ComputerChoice == EnChoice::Paper)
		{
			cout << "______________________Round[" << i << "]_________________________\t\n";
			cout << "Player choice: Scissors " << endl;
			cout << "Computer choice: Paper " << endl;
			cout << "Round Winner:" << "[User] " << endl;
			system("color 2F");
			cout << "\a";
			cout << "___________________________________________________________________\t\t\n";
			UserWonTimes++;
		}
		else if (UserChoice == EnChoice::Stone && ComputerChoice == EnChoice::Scissors)
		{
			cout << "______________________Round[" << i << "]_________________________\t\n";
			cout << "Player choice: Stone " << endl;
			cout << "Computer choice: Scissors " << endl;
			cout << "Round Winner:" << "[User] " << endl;
			system("color 2F");
			cout << "\a";
			cout << "___________________________________________________________________\t\t\n";
			UserWonTimes++;

		}
		else if (UserChoice == EnChoice::Paper && ComputerChoice == EnChoice::Scissors)
		{
			cout << "______________________Round[" << i << "]_________________________\t\n";
			cout << "Player choice: Paper " << endl;
			cout << "Computer choice: Scissors " << endl;
			cout << "Round Winner:" << "[Computer] " << endl;
			system("color 4F");
			cout << "\a";
			cout << "___________________________________________________________________\t\t\n";
			ComputerOwnTimes++;
		}
		else if (UserChoice == EnChoice::Stone && ComputerChoice == EnChoice::Paper)
		{
			cout << "______________________Round[" << i << "]_________________________\t\n";
			cout << "Player choice: Stone " << endl;
			cout << "Computer choice: Paper " << endl;
			cout << "Round Winner:" << "[Computer] " << endl;
			system("color 4F");
			cout << "\a";
			cout << "___________________________________________________________________\t\t\n";
			ComputerOwnTimes++;
		}
		else if (UserChoice == EnChoice::Paper && ComputerChoice == EnChoice::Stone)
		{
			cout << "______________________Round[" << i << "]_________________________\t\n";
			cout << "Player choice: Paper " << endl;
			cout << "Computer choice: Stone " << endl;
			cout << "Round Winner:" << "[User] " << endl;
			system("color 2F");
			cout << "\a";
			cout << "___________________________________________________________________\t\t\n";
			UserWonTimes++;
		}
		
	}
	cout << "\t\t___________________________________________________________________\t\t\n\n1";
	cout << "\t\t\t\t\t\t**Game Over**\t\t\n";
	cout << "\t\t___________________________________________________________________\t\t\n";
}	
char AskUserToPlayAgaen()
{
char YesOrNo;
		cout << "Do you want to play agaen Y/N\n";
		cin >> YesOrNo;
	
	return YesOrNo;
}
void PrintFinallyResult(int NumOfRaound ,int ComputerOwnTimes, int UserWonTimes, int DrawTimes)
{
	PlayRound(NumOfRaound, ComputerOwnTimes, UserWonTimes, DrawTimes);
	cout << "\t\_________________________________Game Result_________________________________\n";
	cout << "\tGame Rounds:" << NumOfRaound << endl;
	cout << "\tPlayer 1 own times " << UserWonTimes << endl;
	cout << "\tComputer own times " << ComputerOwnTimes << endl;
	cout << "\tDraw times " << DrawTimes << endl;
	cout << "\tFinally winner ";
	if (ComputerOwnTimes > UserWonTimes)
	{
	cout<<" [Computer]\n\a";
	system("color 4F");
	}
	else if (ComputerOwnTimes < UserWonTimes)
	{
		cout<< "[Player 1]\n\a";
		system("color 2F");
	}
	else
	{
		cout<<"[Draw]\n\a";
		system("color 6F");
	}
	cout << endl;
}

int main()
{

	int NumOfRaound = ReadNum("How many round do you want 1-10");
	int ComputerOwnTimes=0, UserWonTimes=0, DrawTimes=0;
	PrintFinallyResult(NumOfRaound, ComputerOwnTimes, UserWonTimes, DrawTimes);
	char AskUserToPlayAgaen5 = AskUserToPlayAgaen();
	if (AskUserToPlayAgaen5 == 'Y' || AskUserToPlayAgaen5 == 'y')
	{
		NumOfRaound = ReadNum("How many round do you want 1-10");
		PrintFinallyResult(NumOfRaound, ComputerOwnTimes, UserWonTimes, DrawTimes);
	}
}*/

//Teacher solve
#include<iostream>
#include<cstdlib>
using namespace std;
enum enGameChoice {Paper=1,Stone=2,Scissor=3};

enum enWinner { Player1=1,Computer=2,Drwe=3};

struct StRoundInfo
{
	short RoundNum ;
	enGameChoice ChoicePlayer1 ;
	enGameChoice ChoiceComputer ;
	enWinner Winner;
	string NameWinner ;
};

struct StGameResult
{
	short RoundGame;
	short Player1OwnTimes ;
	short ComputerOwnTimes ;
	short DrwaTimes ;
	enWinner GameWinner;
	string NameGameWinner ;

};

int ReadHowManyRound()
{
	int Num = 0;
	do
	{
		cout << "How many round do you want to play\n";
		cin>>Num;
	} while (Num < 1 || Num>10);
	return Num;
}

enGameChoice ReadPlayer1Choice(StRoundInfo RoundInfo)
{
	short Num = 0;
	do
	{
		cout << "Your choice:[1]:Paper[2]:Stone[3]:Scissor\n";
		cin>> Num;
	} while (Num < 1 || Num>3);
	return enGameChoice(Num);
}

int RandomNum(int From, int To)
{
	int Random = 0;
	Random = rand() % (To - From + 1) + From;
	return Random;
}

enGameChoice GetComputerChoice()
{
	int Choice = 0;
	Choice = RandomNum(1, 3);
	return enGameChoice(Choice);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

string Tibs(short HowManyTibs)
{
	string T = "";
	for (int i = 1;i <= HowManyTibs;i++)
	{
		T = T + "\t";
	}
	
	return T;
}

void PrintGameOver()
{
	cout << Tibs(2) << "_________________________________________________________________\n";
	cout << Tibs(6) << "Game Over\n";
	cout<< Tibs(2) << "_________________________________________________________________\n\n";
}

string NameWinner(enWinner Winner)
{
	string arrWinnerName[3] = { "[Player1]","[Computer]","[Drwa]" };
	return arrWinnerName[Winner-1];
}

string NameChoice(enGameChoice Choice)
{
	string arrChoiceString[3] = { "Paper","Stone", "Scissor" };
	return arrChoiceString[Choice - 1];
}

enWinner WhoOwnTheRound(StRoundInfo RoundInfo)
{
	if (RoundInfo.ChoicePlayer1 == RoundInfo.ChoiceComputer)
	{
		return enWinner::Drwe;
	}
	switch (RoundInfo.ChoicePlayer1)
	{
	case enGameChoice::Paper:
		if (RoundInfo.ChoiceComputer == enGameChoice::Scissor)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Stone:
		if (RoundInfo.ChoiceComputer == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Scissor:
		if (RoundInfo.ChoiceComputer == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::Player1;

}

void SetWinnerScreen(StRoundInfo RoundInfo)
{
	if (RoundInfo.Winner == 1)
	{
		system("color 2F");
		cout << "\a";
	}
	else if (RoundInfo.Winner == 2)
	{
		system("color 4F");
		cout << "\a";
	}
	else
	{
		system("color 6F");
		cout << "\a";
	}
}

void printRoundResult(StRoundInfo RoundInfo)
{
	cout << "__________________________" << RoundInfo.RoundNum << "________________________\n";
	cout <<  "Player1 Choice :" << NameChoice(RoundInfo.ChoicePlayer1) << endl;
	cout<< "Computer choice :"<< NameChoice(RoundInfo.ChoiceComputer) << endl;
	cout<<"Round Winner: " <<RoundInfo.NameWinner << endl;

	SetWinnerScreen(RoundInfo);
}

enWinner WhoWinnerFinal(short Player1OwnTimes, short ComputerOwnTimes)
{
	
	if (Player1OwnTimes > ComputerOwnTimes)
	{
		return enWinner::Player1;
	}
	else if (Player1OwnTimes < ComputerOwnTimes)
	{
		return enWinner::Computer;
	}
	else
		return enWinner::Drwe;
}

StGameResult FillGameResult(int HowManyRound,short Player1OwnTimes, short ComputerOwnTimes, short DrwaTimes)
{
	StGameResult GameResult;
	GameResult.RoundGame = HowManyRound;
	GameResult.Player1OwnTimes = Player1OwnTimes;
	GameResult.ComputerOwnTimes = ComputerOwnTimes;
	GameResult.DrwaTimes = DrwaTimes;
	GameResult.GameWinner = WhoWinnerFinal(Player1OwnTimes, ComputerOwnTimes);
	GameResult.NameGameWinner = NameWinner(GameResult.GameWinner);
	return GameResult;
}

StGameResult PlayGame(int HowManyRound)
{
	
	StRoundInfo RoundInfo;
	short Player1OwnTimes=0, ComputerOwnTimes=0, DrwaTimes=0;
	for (int RoundGame = 1;RoundGame <= HowManyRound;RoundGame++)
	{
		cout << "Round[" << RoundGame << "] bigins\n";
		RoundInfo.RoundNum = RoundGame;
		RoundInfo.ChoicePlayer1 = ReadPlayer1Choice(RoundInfo);
		RoundInfo.ChoiceComputer = GetComputerChoice();
		RoundInfo.Winner = WhoOwnTheRound(RoundInfo);
		RoundInfo.NameWinner = NameWinner(RoundInfo.Winner);
		
		if (RoundInfo.Winner == 1)
		{
			Player1OwnTimes++;
		}
		else if(RoundInfo.Winner == 2)
		{
			ComputerOwnTimes++;
		}
		else
		{
			DrwaTimes++;
		}
		printRoundResult(RoundInfo);
	}
	
	return  FillGameResult(HowManyRound,Player1OwnTimes, ComputerOwnTimes, DrwaTimes);
}

void ShowFinallyResult(StGameResult Result)
{
	cout << Tibs(2) << "_______________________________ Game Result___________________________\n\n";
	cout << Tibs(1) <<"Game Rounds: " << Result.RoundGame << endl;
	cout << Tibs(1) <<"Player 1 own times: " << Result.Player1OwnTimes << endl;
	cout << Tibs(1) <<"Computer own times :" << Result.ComputerOwnTimes << endl;
	cout << Tibs(1) <<"Drwa times : " << Result.DrwaTimes << endl;
	cout << Tibs(1) << "Winner Game: " << Result.NameGameWinner << endl;
}

void StartGame()
{
	char PlayAgain;
	do
	{
		ResetScreen();
		StGameResult Result = PlayGame(ReadHowManyRound());
		PrintGameOver();
		ShowFinallyResult(Result);
		cout << endl;
		cout<< Tibs(2) << "Do you whant to play again Y/N\n";
		cin>> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
}
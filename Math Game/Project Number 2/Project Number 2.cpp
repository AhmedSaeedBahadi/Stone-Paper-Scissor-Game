#include<iostream>
#include<cstdlib>
using namespace std;

enum enQuestionLevel{EasyLevel=1,MedLevel=2,HurdLevel=3,MixLevel=4};
enum enOperationType{Add=1,Sul=2,Mul=3,Divid=4, MixOp = 5 };
struct stQuestion
{
	short Number1 = 0;
    short Number2 = 0;
	enOperationType QuestionOP;
	enQuestionLevel QuestionLevel;
	int CorectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion  QuestionList[100];
	int NumberOfQuestion = 0;
	enOperationType QuestionOP;
	enQuestionLevel QuestionLevel;
	int NumberOfWrongAnswer= 0;
	int NumberOfRightAnswer = 0;
	bool IsPass = false;
};

short ReadHowManyQueation()
{
	short ManyQuestion = 0;
	do
	{
		cout << "How many question do you want to answer\n";
		cin >> ManyQuestion;
	} while (ManyQuestion < 1 || ManyQuestion>10);
	return  ManyQuestion;
}

enQuestionLevel ReadQuestionLevel()
{
	short Level = 0;
	do
	{
		cout << "Enter Questions Level [1]:Easy,[2]:Med,[4]:Mix\n";
		cin >> Level;
	} while (Level < 1 || Level>4);
	return enQuestionLevel(Level);
}

enOperationType ReadOperationType()
{
	short Operation = 0;
	do
	{
		cout << "Enter operation type [1]:Add,[2]:Sul,[3]:Mul,[4]:Divid,[5]:Mix\n";
		cin >> Operation;
	} while (Operation < 1 || Operation>5);
	return enOperationType(Operation);
}

int SimpleChaculater(short Num1, short Num2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Num1 + Num2;
	case enOperationType::Sul:
		return Num1 - Num2;
	case enOperationType::Mul:
		return Num1 * Num2;
	case enOperationType::Divid:
		return Num1 / Num2;
	}

}

int RandomNumber(int From, int To)
{
	int RandomNum = 0;
	RandomNum = rand() % (From - To + 1) + From;
	return RandomNum;
}

enOperationType  RandomOpType()
{
	short OpType = 0;
	OpType = RandomNumber(1, 4);
	return enOperationType(OpType);
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OpType)
{
	stQuestion Question;
	if (OpType == enOperationType::MixOp)
	{
		OpType = RandomOpType();
	}
	if (QuestionLevel == enQuestionLevel::MixLevel)
	{
		QuestionLevel = enQuestionLevel(RandomNumber(1, 3));
	}
	Question.QuestionOP = OpType;
	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.QuestionLevel = QuestionLevel;
		Question.CorectAnswer = SimpleChaculater(Question.Number1, Question.Number2, Question.QuestionOP);
		return Question;
	case enQuestionLevel::MedLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.QuestionLevel = QuestionLevel;
		Question.CorectAnswer = SimpleChaculater(Question.Number1, Question.Number2, Question.QuestionOP);
		return Question;
	case enQuestionLevel::HurdLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.QuestionLevel = QuestionLevel;
		Question.CorectAnswer = SimpleChaculater(Question.Number1, Question.Number2, Question.QuestionOP);
		return Question;
	}


}

void GenerateQuestionsQuizz(stQuizz& Quizz)
{
	for (int Question = 0;Question < Quizz.NumberOfQuestion;Question++)
	{
		Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.QuestionOP);
	}
}

string GetOperationSymple(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sul:
		return "-";
	case enOperationType::Mul:
		return "*";
	case enOperationType::Divid:
		return "/";
	default:
	return 	"Mix";
	}
}

void PrintTheQuestion(stQuizz Quizz, short QuestionNumber)
{
	cout << "Question[" << QuestionNumber << "/" << Quizz.NumberOfQuestion << "]\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2;
	cout << GetOperationSymple(Quizz.QuestionList[QuestionNumber].QuestionOP) << endl;
	cout << "____________________\n";
}

int ReadAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void setScreenColor(bool Right)
{
	if (Right)
	{
		system("color 2F");
	  cout << "\a";
	}
	else
	{
		system("color 4F");
		cout << "\a";
	}
	cout << " ";
}

void corectQuestionList(stQuizz &Quizz,short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswer++;
		cout << "Wrong Answer(-:\n";
		cout << "The Right Answer is " << Quizz.QuestionList[QuestionNumber].CorectAnswer << endl;
	}
	else if (Quizz.QuestionList[QuestionNumber].PlayerAnswer == Quizz.QuestionList[QuestionNumber].CorectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswer++;
		cout << "Right Answer)-:\n";
		
	}
	setScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

void AskAndCorectQuestionList(stQuizz& Quizz)
{
	for (int QuestionNumber = 0;QuestionNumber < Quizz.NumberOfQuestion;QuestionNumber++)
	{
		PrintTheQuestion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadAnswer();
		corectQuestionList(Quizz, QuestionNumber);
	}

	Quizz.IsPass = (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWrongAnswer);

}

string GetFinalyResultText(bool Pass)
{
	if (Pass)
	{
		return "Pass)-:\n";
	}
	else 
	{
		return "Fail (-:\n";
	}
}

string GetQuizzLevelText(enQuestionLevel Level)
{
	string arrQuestionLevelText[4] = { "Easy","Med","Hurd","Mix" };
	return arrQuestionLevelText[Level - 1];
}

void PrintResultQuizz(stQuizz Quizz)
{
	cout << "\n_______________________________________________________________________\n";
	cout << "Finaly Result is " << GetFinalyResultText(Quizz.IsPass) << endl;
	cout << "\n_______________________________________________________________________\n";
	cout << "Number of Question: " << Quizz.NumberOfQuestion << endl;
	cout << "OpType: " << GetOperationSymple(Quizz.QuestionOP) << endl;
	cout << "Quizz Level: " << GetQuizzLevelText(Quizz.QuestionLevel) << endl;
	cout << "Number of right answer: " << Quizz.NumberOfRightAnswer << endl;
	cout << "Number of wrong answer: " << Quizz.NumberOfWrongAnswer << endl;
}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestion = ReadHowManyQueation();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.QuestionOP = ReadOperationType();
		
		GenerateQuestionsQuizz(Quizz);
	AskAndCorectQuestionList(Quizz);
	PrintResultQuizz(Quizz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'y';
	do
	{
		ResetScreen();
		PlayMathGame();
		cout << "\nDo you want to play again\n";
		cin >> PlayAgain;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}
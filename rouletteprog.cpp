#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<time.h>

using namespace std;

char r,w,bettype, color,o,p;
char a,b,c,d,e,f,h,i,j,k,l,m;
int playercash[4];
int playerbet;
int board[12][3];
int numbr = 1;
int searchnum = 0;
bool found = false;
int split[2];
char splitop, cornerop, oddevenop, lineop;
int q =0, z, n1, n2, y;
int streetsel = 0;
int street[3];
int corner1, corner2;
int corner[4];
int basket[5];
int line1, line2;
int line[6];
int columnop;
int dozenop;
int dozen1[12] = {1,4,7,10,13,16,19,22,25,28,31,34};
int dozen2[12]  = {2,5,8,11,14,17,20,23,26,29,32,35};

int dozen3[12] = {3,6,9,12,15,18,21,24,27,30,33,36};
int colorr[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
int colorw[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
int outcome;
int betamount;
int availablebal;

int main()
{
	availablebal = 20;
	for(int s = 0; s < 12; s++)
	{
		for(int t = 0; t < 3; t++)
		{
			board[s][t] = numbr++;
		}
		cout<<endl;
	}
	cout<<"issued credit is $20."<<endl;
  while(1)
  {
  	if(availablebal ==0)
  	{
  		cout<<"your avaiable balance is 0. game over!"<<endl;
  		return 0;
  	}
	cout<<"enter amount to bet"<<endl;
	cout<<"enter -999 to quit"<<endl;
	cin>>betamount;
	cout<<endl<<endl;
	if(betamount == -999)
	{
			cout<<"exiting game."<<endl;
			cout<<"final balance is $"<<availablebal<<".00."<<endl;
			return 0;
	}
	cout<<endl;
	while(betamount> availablebal)
	{
		cout<<"invalid bet. please try again."<<endl;
		cout<<"available balance is "<<availablebal<<"."<<endl;
		cout<<"enter amount to bet"<<endl;
		cout<<"enter -999 to quit"<<endl;
		cin>>betamount;
		cout<<endl<<endl;
		if(betamount == -999)
		{
			cout<<"exiting game."<<endl;
			cout<<"final balance is $"<<availablebal<<".00."<<endl;
			return 0;
		}
	}
	availablebal -= betamount;
	cout<<"enter type of bet:"<<endl<<
	"A. Straight up 35:1"<<endl<<
	"- bet is placed on a single number"<<endl<<endl<<
	"B. Split 17:1"<<endl<<
	"- bet splits 2 numbers"<<endl<<endl<<
	"C. Street 11:1"<<endl<<
	"- bet covers 3 numbers in a row"<<endl<<endl<<
	"D. Corner 8:1"<<endl<<
	"- bet covers 4 numbers"<<endl<<endl<<
	"E. Basket 6:1"<<endl<<
	"- bet covers 1,2,3 and both zeros"<<endl<<endl<<
	"F. Line 5:1"<<endl<<
	"- bet covers 6 numbers in 2 rows"<<endl<<endl<<
	"G. Column 2:1"<<endl<<
	"- bet covers 12 numbers"<<endl<<endl<<
	"H. Dozen 2:1"<<endl<<
	"- bet covers 12 numbers"<<endl<<endl<<
	"I. Low Number 1:1"<<endl<<
	"- bet covers numers 1-18"<<endl<<endl<<
	"J. High Number 1:1"<<endl<<
	"- bet covers numbers 19-36"<<endl<<endl<<
	"K. Red/White 1:1"<<endl<<
	"- bet covers red or black numbers"<<endl<<endl<<
	"L. Odd/Even 17:1"<<endl<<
	"- bet covers odd or even numbers"<<endl<<endl<<
	"M. Zero Split 17:1"<<endl<<
	"- bet splits both zeros"<<endl<<endl<<
	"Q. Quit game"<<endl<<endl;
	cin>>bettype;
	cout<<endl<<endl;
	tolower(bettype);
	switch(bettype)
	{
		case 'a':
			cout<<"enter number to place bet on."<<endl;
			cout<<"enter number 37 to place bet on 0."<<endl;
			cout<<"enter number 38 to place bet on 00."<<endl;
			cin>>playerbet;
			if(playerbet> 38 || playerbet < 0)
			{
				while(playerbet> 36)
				cout<<"invalid entry. option range is 1 - 38. please try again."<<endl;
				cin>>playerbet;
			}
		break;
		case 'b':
			cout<<"enter 1 of the 2 numbers to bet on"<<endl;
			cin>>playerbet;
			//if(playerbet 36)
		//	{
				
				while(playerbet > 36)
				{
					cout<<"invalid bet."<<endl;
					cout<<"enter 1 of the 2 numbers to bet on"<<endl;
					cin>>playerbet;	
				}
		//	}
					for(y = 0; y <12; y++)
					{
						for(z=0; z < 3; z++)
						{
							if(board[y][z] == playerbet)
							{
								n1 = y;
								n2 = z;
								break;
							}
							
						}
					}
			
			
			
			if(n1 == 0)
			{
				cout<<"the only possible split option for your selection is:"<<endl;
				cout<<board[n1+1][n2]<<endl;
				split[0]= playerbet;
				split[1]= board[n1+1][n2];
				cout<<"you bet a "<<playerbet<<" , "<<board[n1+1][n2]<<" split."<<endl;
				cout<<endl<<endl<<endl;
			}
			else if(n1 == 11)
			{
				cout<<"the only possible split option for your selection is:"<<endl;
				cout<<board[n1-1][n2]<<endl;
				split[0]= playerbet;
				split[1]= board[n1-1][n2];
				cout<<"you bet a "<<board[n1-1][n2]<<" , "<<playerbet<<" split."<<endl;
				cout<<endl<<endl<<endl;
			}
			else
			{
				cout<<"possible split options for your selection are:"<<endl;
				cout<<"option 1: "<<board[n1-1][n2]<<" and option 2: "<<board[n1+1][n2]<<endl;
				cout<<"which option do you prefer?"<<endl;
				cout<<"enter s for option 1 and t for option 2"<<endl;
				cin>>splitop;
				if(splitop =='s')
				{
					split[0]= playerbet;
					split[1]= board[n1-1][n2];
					cout<<"you bet a "<<board[n1-1][n2]<<" , "<<playerbet<<" split."<<endl;
					cout<<endl<<endl<<endl;
				}
				else if(splitop =='t')
				{
					split[0]= playerbet;
					split[1]= board[n1+1][n2];
					cout<<"you bet a "<<playerbet<<" , "<<board[n1+1][n2]<<" split."<<endl;
					cout<<endl<<endl<<endl;
				}
				else
				{
					//q = y;
					cout<<"invalid input. please try again."<<endl;
					cin>>splitop;
					while(splitop != 's' && splitop != 't')
					{
						cout<<"possible split options for your selection are:"<<endl;
						cout<<"option 1: "<<board[n1-1][n2]<<" and option 2: "<<board[n1+1][n2]<<endl;
						cout<<"which option do you prefer?"<<endl;
						cout<<"enter s for option 1 and t for option 2"<<endl;
						cin>>splitop;
					}
					if(splitop =='s')
					{
						split[0]= playerbet;
						split[1]= board[n1-1][n2];
						cout<<"you bet a "<<board[n1-1][n2]<<" , "<<playerbet<<" split."<<endl;
						cout<<endl<<endl<<endl;
					}
					else
					{
						split[0]= playerbet;
						split[1]= board[n1+1][n2];
						cout<<"you bet a "<<playerbet<<" , "<<board[n1+1][n2]<<" split."<<endl;
						cout<<endl<<endl<<endl;
					}
				}
			}
		break;
		case 'c':
			cout<<"indicate the row you want to select."<<endl;
			cin>>streetsel;
			streetsel = streetsel-1;
			while(streetsel > 12)
			{
				cout<<"invalid row selection."<<endl;
				cout<<"indicate the row you want to select."<<endl;
				cin>>streetsel;
				streetsel = streetsel-1;
			}
			cout<< "your selection was row "<<streetsel +1<<" containing numbers:"<<endl
			<<board[streetsel][0]<<", "<<board[streetsel][1]<<" and "<<board[streetsel][2]<<endl;
			cout<<endl<<endl<<endl;
			street[0] = board[streetsel][0];
			street[1] = board[streetsel][1];
			street[2] = board[streetsel][2];
		break;
		case 'd':
			cout<<"enter the 2 rows that your corner exists in"<<endl;
			cout<<"one at a time followed by enter."<<endl;
			cin>>corner1;
			cin>>corner2;
			cout<<"possible corner options for your selection are:"<<endl;
			cout<<"option 1: "<<board[corner1][0]<<", "<<board[corner1][1]
			<<" : "<<board[corner2][0]<<", "<<board[corner2][1]
			<<" and option 2: "<<board[corner1][1]<<", "<<board[corner1][2]
			<<" : "<<board[corner2][1]<<", "<<board[corner2][2]<<"."<<endl;
			cout<<"which option do you prefer?"<<endl;
			cout<<"enter s for option 1 and t for option 2"<<endl;
			cin>>cornerop;
			if(cornerop =='s')
				{
					corner[0]= board[corner1][0];
					corner[1]= board[corner2][0];
					corner[2]= board[corner1][1];
					corner[3]= board[corner2][1];
				}
				else if(splitop =='t')
				{
					corner[0]= board[corner1][0];
					corner[1]= board[corner2][0];
					corner[2]= board[corner1][1];
					corner[3]= board[corner2][1];
				}
				else
				{
					cout<<"invalid input. please try again."<<endl;
					cin>>cornerop;
					while(cornerop != 's' && cornerop != 't')
					{
						cout<<"possible corner options for your selection are:"<<endl;
						cout<<"option 1: "<<board[corner1][0]<<", "<<board[corner1][1]
						<<" : "<<board[corner2][0]<<", "<<board[corner2][1]
						<<" and option 2: "<<board[corner1][1]<<", "<<board[corner1][2]
						<<" : "<<board[corner2][1]<<", "<<board[corner2][2]<<"."<<endl;
						cout<<"which option do you prefer?"<<endl;
						cout<<"enter s for option 1 and t for option 2"<<endl;
						cin>>cornerop;
						if(cornerop =='s')
						{
							cout<<"you selected the corner containing numbers : "<<board[corner1][0]<<", "<<board[corner1][1]
							<<" : "<<board[corner2][0]<<", "<<board[corner2][1]<<endl;
							cout<<endl<<endl<<endl;
							corner[0]= board[corner1][0];
							corner[1]= board[corner2][0];
							corner[2]= board[corner1][1];
							corner[3]= board[corner2][1];
						}
						else
						{
							cout<<"you selected the corner containing numbers : "<<board[corner1][0]<<", "<<board[corner1][1]
							<<" : "<<board[corner2][0]<<", "<<board[corner2][1]<<endl;
							cout<<endl<<endl<<endl;
							corner[0]= board[corner1][0];
							corner[1]= board[corner2][0];
							corner[2]= board[corner1][1];
							corner[3]= board[corner2][1];
						}
					}
				}
		break;
		case 'e':
			cout<<"you selected basket your numbers are 00, 0, 1, 2 and 3."<<endl;
			cout<<endl<<endl<<endl;
			basket[0] = 0;
			basket[1] = 00;
			basket[2] = 1;
			basket[3] = 2;
			basket[4] = 3;
		break;
		case 'f':		
			cout<<"indicate the first row you want to select."<<endl;
			cin>>line1;
			line1 = line1-1;
			while(line1 > 12)
			{
				cout<<"invalid row selection."<<endl;
				cout<<"indicate the first row you want to select."<<endl;
				cin>>line1;
				line1 = line1-1;
			}
			cout<< "your selection was row "<<line1 +1<<" containing numbers:"<<endl
			<<board[line1][0]<<", "<<board[line1][1]<<" and "<<board[line1][2]<<endl;
			line[0] = board[line1][0];
			line[1] = board[line1][1];
			line[2] = board[line1][2];
			
			if(line1 == 0)
			{
				cout<<"the only possible row option for your selection is:"<<endl;
				cout<<line1+1<<endl;
				line2 = line1+1;
				cout<<"you bet a line containing numbers "<<board[line1][0]<<", "<<board[line1][1]<<" , "<<board[line1][2]<<" , "<<board[line2][0]<<", "<<board[line2][1]<<" and "<<board[line2][2]<<endl;
				cout<<endl<<endl<<endl;
				line[3] = board[line2][0];
				line[4] = board[line2][1];
				line[5] = board[line2][2];
			}
			else if(n1 == 11)
			{
				cout<<"the only possible split option for your selection is:"<<endl;
				cout<<line1-1<<endl;
				line2 = line1 - 1;
				cout<<"you bet a line containing numbers "<<board[line2][0]<<", "<<board[line2][1]<<" , "<<board[line2][2]<<" , "<<board[line1][0]<<", "<<board[line1][1]<<" and "<<board[line1][2]<<endl;
				cout<<endl<<endl<<endl;
				line[3] = board[line2][0];
				line[4] = board[line2][1];
				line[5] = board[line2][2];
			}
			else
			{
				cout<<"possible row options for your line selection are:"<<endl;
				cout<<"option 1: "<<line1-1<<" and option 2: "<<line1+1<<endl;
				cout<<"which option do you prefer?"<<endl;
				cout<<"enter s for option 1 and t for option 2"<<endl;
				cin>>lineop;
				if(lineop =='s')
				{
					line2 = line1 -1;
					cout<<"you bet a line containing numbers "<<board[line2][0]<<", "<<board[line2][1]<<" , "<<board[line2][2]<<" , "<<board[line1][0]<<", "<<board[line1][1]<<" and "<<board[line1][2]<<endl;
					cout<<endl<<endl<<endl;
					line[3] = board[line2][0];
					line[4] = board[line2][1];
					line[5] = board[line2][2];
				}
				else if(lineop =='t')
				{
					line2 = line1 +1;
					cout<<"you bet a line containing numbers "<<board[line1][0]<<", "<<board[line1][1]<<" , "<<board[line1][2]<<" , "<<board[line2][0]<<", "<<board[line2][1]<<" and "<<board[line2][2]<<endl;
					cout<<endl<<endl<<endl;
					line[3] = board[line2][0];
					line[4] = board[line2][1];
					line[5] = board[line2][2];
				}
				else
				{
					//q = y;
					cout<<"invalid input. please try again."<<endl;
					cin>>lineop;
					while(lineop != 's' && lineop != 't')
					{
						cout<<"possible row options for your line selection are:"<<endl;
						cout<<"option 1: "<<line1-1<<" and option 2: "<<line1+1<<endl;
						cout<<"which option do you prefer?"<<endl;
						cout<<"enter s for option 1 and t for option 2"<<endl;
						cin>>lineop;
					}
					if(lineop =='s')
					{
						line2 = line1 -1;
						cout<<"you bet a line containing numbers "<<board[line2][0]<<", "<<board[line2][1]<<" , "<<board[line2][2]<<" , "<<board[line1][0]<<", "<<board[line1][1]<<" and "<<board[line1][2]<<endl;
						cout<<endl<<endl<<endl;
						line[3] = board[line2][0];
						line[4] = board[line2][1];
						line[5] = board[line2][2];
					}
					else
					{
						line2 = line1 +1;
						cout<<"you bet a line containing numbers "<<board[line1][0]<<", "<<board[line1][1]<<" , "<<board[line1][2]<<" , "<<board[line2][0]<<", "<<board[line2][1]<<" and "<<board[line2][2]<<endl;
						cout<<endl<<endl<<endl;
						line[3] = board[line2][0];
						line[4] = board[line2][1];
						line[5] = board[line2][2];
					}
				}
			}
			
		break;
		case 'g':
			cout<<"you selected column please enter 1, 2, or 3"<<endl;
			cin>>columnop;
			if(columnop ==1)
			{
				cout<<"your selected numbers are 1 - 12."<<endl;
				cout<<endl<<endl<<endl;
			}
			else if(columnop == 2)
			{
				cout<<"your selected numbers are 13 - 24."<<endl;
				cout<<endl<<endl<<endl;
			}
			else if(columnop == 3)
			{
				cout<<"your selected numbers are 24 - 36."<<endl;
				cout<<endl<<endl<<endl;
			}
			else
			{
				while(columnop >3 || columnop < 1)
				{
					cout<<"invalid selection."<<endl;
					cout<<"you selected column please enter 1, 2, or 3"<<endl;
					cin>>columnop;					
				}

				if(columnop ==1)
				{
					cout<<"your selected numbers are 1 - 12."<<endl;
					cout<<endl<<endl<<endl;
				}
				else if(columnop == 2)
				{
					cout<<"your selected numbers are 13 - 24."<<endl;
					cout<<endl<<endl<<endl;
				}
				else if(columnop == 3)
				{
					cout<<"your selected numbers are 24 - 36."<<endl;
					cout<<endl<<endl<<endl;
				}
			}
		break;
		case 'h':
				cout<<"you selected dozen please enter 1, 2, or 3"<<endl;
			cin>>dozenop;
			if(dozenop ==1)
			{
				cout<<"your selected numbers are 1,4,7,10,13,16,19,22,25,28,31,34."<<endl;
				cout<<endl<<endl<<endl;
			}
			else if(dozenop == 2)
			{
				cout<<"your selected numbers are 2,5,8,11,14,17,20,23,26,29,32,35."<<endl;
				cout<<endl<<endl<<endl;
			}
			else if(dozenop == 3)
			{
				cout<<"your selected numbers are 3,6,9,12,15,18,21,24,27,30,33,36."<<endl;
				cout<<endl<<endl<<endl;
			}
			else
			{
				while(dozenop >3 || dozenop < 1)
				{
					cout<<"invalid selection."<<endl;
					cout<<"you selected dozen please enter 1, 2, or 3"<<endl;
					cin>>dozenop;					
				}

				if(dozenop ==1)
				{
					cout<<"your selected numbers are 1,4,7,10,13,16,19,22,25,28,31,34."<<endl;
					cout<<endl<<endl<<endl;
				}
				else if(dozenop == 2)
				{
					cout<<"your selected numbers are 2,5,8,11,14,17,20,23,26,29,32,35."<<endl;
					cout<<endl<<endl<<endl;
				}
				else if(dozenop == 3)
				{
					cout<<"your selected numbers are 3,6,9,12,15,18,21,24,27,30,33,36."<<endl;
					cout<<endl<<endl<<endl;
				}
			}
		break;
		case 'i':
			cout<<"you selected low number your numbers are 1 - 18."<<endl;
			cout<<endl<<endl<<endl;
		break;
		case 'j':
			cout<<"you selected high number your numbers are 19 - 36."<<endl;
			cout<<endl<<endl<<endl;
		break;
		case 'k':
			cout<<"you selected red/ white please enter r for red and w for white."<<endl;
			cin>>color;
			if(color == 'r')
			{
				cout<<"you placed your bet on red."<<endl;
				cout<<endl<<endl<<endl;
				break;
			}
			else if(color == 'w')
			{
				cout<<"you placed your bet on white."<<endl;
				cout<<endl<<endl<<endl;
				break;
			}
			else
			{
				while(color != 'r' && color != 'w')
				{
					cout<<"invalid selection."<<endl;
					cout<<"you selected red/ white please enter r for red and w for white."<<endl;
					cin>>color;	
				}
				if(color == 'r')
				{
					cout<<"you placed your bet on red."<<endl;
					//cout<<"your selected numbers are 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34 and 36."<<endl;
					cout<<endl<<endl<<endl;
					break;
				}
				else if(color == 'w')
				{
					cout<<"you placed your bet on white."<<endl;
					//cout<<"your selected numbers are 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33 and 35."<<endl;
					cout<<endl<<endl<<endl;
					break;
				}
			}
		break;
		case 'l':
			cout<<"you selected odd/even please enter o for odd or p for even."<<endl;
			cin>>oddevenop;
			if(oddevenop == 'o')
			{
				cout<<"you bet on odd."<<endl;
				cout<<endl<<endl<<endl;
			}
			else if(oddevenop =='p')
			{
				cout<<" you bet even."<<endl;
				cout<<endl<<endl<<endl;
			}
			else
			{
				while(oddevenop != 'o' && oddevenop != 'p')
				{
					cout<<"invalid selection."<<endl;
					cout<<"you selected odd/even please enter o for odd or p for even."<<endl;
					cin>>oddevenop;
				}
				if(oddevenop == 'o')
				{
					cout<<"you bet on odd."<<endl;
					cout<<endl<<endl<<endl;
				}
				else
				{
					cout<<" you bet even."<<endl;
					cout<<endl<<endl<<endl;
				}
				break;				
			}
		break;
		case 'm':
			cout<<"you selected zerosplit you bet on zeros."<<endl;
			cout<<endl<<endl<<endl;
		break;
		case 'q':
			cout<<"exiting game."<<endl;
			cout<<"final balance is $"<<availablebal<<".00."<<endl;
			return 0;
		break;
		default:
			cout<<"invalid selection. program ending."<<endl;
//			cin>>bettype;
//			tolower(bettype);
//			switch(bettype)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		break;
	}
	srand ( time(NULL) );
	outcome = rand() % 38 + 1;
	cout<<"the roulette ball landed on "<<outcome<<"!"<<endl<<endl;
	switch(bettype)
	{
		case 'a':
			cout<<"you bet on "<<playerbet<<"."<<endl;
			if(playerbet == outcome)
			{
				cout<<"you win!!"<<endl;
				betamount = betamount*35;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
			}

			
		break;
		case 'b':
			cout<<"you bet a "<<split[0]<<" , "<<split[1]<<" split."<<endl;
			if(split[0] == outcome || split[1] == outcome)
			{
				cout<<"you win!!"<<endl;
				betamount = betamount*17;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
			}
	
		break;
		case 'c':
			cout<< "your selection was row "<<streetsel<<" containing numbers:"<<endl
			<<street[0]<<", "<<street[1]<<" and "<<street[2]<<endl;
			if(street[0] == outcome || street[1] == outcome|| street[3] == outcome)
			{
				cout<<"you win!!"<<endl;
				betamount = betamount*11;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
			}
		break;
		case 'd':
			cout<<"you selected the corner containing numbers : "<<corner[0]<<", "<<corner[1]
			<<" : "<<corner[2]<<", "<<corner[3]<<endl;
			if(corner[0] == outcome || corner[1] == outcome|| corner[3] == outcome || corner[4] == outcome)
			{
				cout<<"you win!!"<<endl;
				betamount = betamount*8;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
			}
					
				
		break;
		case 'e':
			cout<<"you selected basket your numbers are 00, 0, 1, 2 and 3."<<endl;
			if(outcome == 1 ||outcome ==2 || outcome ==3 || outcome == 37 || outcome ==38)
			{
				cout<<"you win!!"<<endl;
				betamount = betamount*6;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
		    }
						
		break;
		case 'f':		

			cout<<"you bet a line containing numbers "<<line[0]<<", "<<line[1]<<" , "<<line[2]<<" , "<<line[3]<<", "<<line[4]<<" and "<<line[5]<<"."<<endl;
			if(outcome == line[0] ||outcome == line[1] || outcome == line[2] || outcome == line[3] || outcome ==line[4] || outcome ==line[5])
			{
				cout<<"you win!!"<<endl;
				betamount = betamount*5;
				cout<<"your payout is "<< betamount <<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
		    }
		break;
		case 'g':
			if(columnop ==1)
			{
			cout<<"you bet a colum of 1 - 12."<<endl;				
				if(outcome >0 && outcome < 13)
				{
					cout<<"you win!!"<<endl;
					betamount = betamount*2;
					cout<<"your payout is "<< betamount<<"!!"<<endl;
					availablebal += betamount;
					cout<<"new balance = "<<availablebal<<endl<<endl;
					betamount = 0;
					break;
				}
				else
				{
					cout<<"you did not win. better luck next time!"<<endl;
					cout<<"balance = "<<availablebal<<endl<<endl;
		    	}
			}
			else if(columnop == 2)
			{
				cout<<"you bet a colum of 13 - 24."<<endl;
				if(outcome >12 && outcome < 25)
				{
					cout<<"you win!!"<<endl;
					betamount = betamount*2;
					cout<<"your payout is "<< betamount<<"!!"<<endl;
					availablebal += betamount;
					cout<<"new balance = "<<availablebal<<endl<<endl;
					betamount = 0;
					break;
				}
				else
				{
					cout<<"you did not win. better luck next time!"<<endl;
					cout<<"balance = "<<availablebal<<endl<<endl;
		    	}
			}
			else
			{
				cout<<"you bet a colum of 25 - 36."<<endl;
				if(outcome >24 && outcome < 37)
				{
					cout<<"you win!!"<<endl;
					betamount = betamount*2;
					cout<<"your payout is "<< betamount<<"!!"<<endl;
					availablebal += betamount;
					cout<<"new balance = "<<availablebal<<endl<<endl;
					betamount = 0;
					break;
				}
				else
				{
					cout<<"you did not win. better luck next time!"<<endl;
					cout<<"balance = "<<availablebal<<endl<<endl;
		    	}
			}
		break;
		case 'h':
			if(dozenop ==1)
			{
				cout<<"your selected numbers are 1,4,7,10,13,16,19,22,25,28,31,34."<<endl;	
				{
					if(dozen1[i] == outcome)
					{
						cout<<"you win!!"<<endl;
						betamount = betamount*2;
						cout<<"your payout is "<< betamount<<"!!"<<endl;
						availablebal += betamount;
						cout<<"new balance = "<<availablebal<<endl<<endl;
						betamount = 0;
						break;		
					}
				}
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
				break;
			}
			else if(dozenop == 2)
			{
				cout<<"your selected numbers are 2,5,8,11,14,17,20,23,26,29,32,35."<<endl;
				{
					if(dozen2[i] == outcome)
					{
						cout<<"you win!!"<<endl;
						betamount = betamount*2;
						cout<<"your payout is "<< betamount <<"!!"<<endl;
						availablebal += betamount;
						cout<<"new balance = "<<availablebal<<endl<<endl;
						betamount = 0;
						break;		
					}
				}
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
				break;				
			}
			else
			{
				cout<<"your selected numbers are 3,6,9,12,15,18,21,24,27,30,33,36."<<endl;
				for(int i = 0; i <12; i++)
				{
					if(dozen3[i] == outcome)
					{
						cout<<"you win!!"<<endl;
						betamount = betamount*2;
						cout<<"your payout is "<< betamount<<"!!"<<endl;
						availablebal += betamount;
						cout<<"new balance = "<<availablebal<<endl<<endl;
						betamount = 0;
						break;		
					}
				}
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
				break;
			}

	
		break;
		case 'i':
			cout<<"you selected low number."<<endl;
			if(outcome >0 && outcome < 19)
			{
				cout<<"you win!!"<<endl;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
		    }
			
		break;
		case 'j':
			cout<<"you selected high number."<<endl;
			if(outcome >18 && outcome < 37)
			{
				cout<<"you win!!"<<endl;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;
		    }
		break;
		case 'k':
			if(color == 'r')
			{
				cout<<"you placed your bet on red."<<endl;
				for(int i = 0; i <18; i++)
				{
					if(colorr[i] == outcome)
					{
						cout<<"you win!!"<<endl;
						betamount = betamount*2;
						cout<<"your payout is "<< betamount<<"!!"<<endl;
						availablebal += betamount;
						cout<<"new balance = "<<availablebal<<endl<<endl;
						betamount = 0;	
					}
				}
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl<<endl;				
				break;
			}
			else
			{
				cout<<"you placed your bet on white."<<endl;
				for(int i = 0; i <18; i++)
				{
					if(colorw[i] == outcome)
					{
						cout<<"you win!!"<<endl;
						betamount = betamount*2;
						cout<<"your payout is "<< betamount<<"!!"<<endl;
						availablebal += betamount;
						cout<<"new balance = "<<availablebal<<endl<<endl;
				 		betamount = 0;		
					}
				}
				cout<<"you did not win. better luck next time!"<<endl;	
				cout<<"balance = "<<availablebal<<endl<<endl;			
				break;
			}
		break;
		case 'l':

			if(oddevenop == 'o')
			{
				cout<<"you bet on oddnumbers."<<endl;
				if(outcome % 2 == 1)
				{
					cout<<"you win!!"<<endl;
					betamount = betamount*17;
					cout<<"your payout is "<< betamount<<"!!"<<endl;
					availablebal += betamount;
					cout<<"new balance = "<<availablebal<<endl<<endl;
					betamount = 0;
					//break;
				}
				else
				{
					cout<<"you did not win. better luck next time!"<<endl;
					cout<<"balance = "<<availablebal<<endl<<endl;
		    	}
			}
			else
			{
				cout<<" you bet even numbers."<<endl;
				if(outcome % 2 == 0)
				{
					cout<<"you win!!"<<endl;
					betamount = betamount*17;
					cout<<"your payout is "<< betamount<<"!!"<<endl;
					availablebal += betamount;
					cout<<"new balance = "<<availablebal<<endl<<endl;
					betamount = 0;
					break;
				}
				else
				{
					cout<<"you did not win. better luck next time!"<<endl;
					cout<<"balance = "<<availablebal<<endl<<endl;
		    	}				
			}
			
		break;
		case 'm':
			cout<<"you selected zerosplit you bet on 0 and 00."<<endl;
			if(outcome == 37 || outcome == 38)
			{
				cout<<"you win!!"<<endl;
				betamount = betamount*17;
				cout<<"your payout is "<< betamount<<"!!"<<endl;
				availablebal += betamount;
				cout<<"new balance = "<<availablebal<<endl;
				betamount = 0;
				break;
			}
			else
			{
				cout<<"you did not win. better luck next time!"<<endl;
				cout<<"balance = "<<availablebal<<endl;
			}
		break;

	}
  }
	system("pause");
	return 0;
}

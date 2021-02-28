#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

//COLORS LIST
//1: Blue
//2: Green
//3: Cyan
//4: Red
//5: Purple
//6: Yellow (Dark)
//7: Default white
//8: Gray/Grey
//9: Bright blue
//10: Brigth green
//11: Bright cyan
//12: Bright red
//13: Pink/Magenta
//14: Yellow
//15: Bright white
//Numbers after 15 include background colors

void Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int main(){
	
	const int distance = 60;
	
	int choice;
	
	do{
		Color(4); // red color
		
		cout<<"1 Go to Wine Shop"<<endl;
		cout<<"2 Go to Juice Shop"<<endl;
		cout<<"3 Exit from program"<<endl;
		
		/* asking today program of a User by taking his choice*/
		
		cout<<"\n\tEnter Your Choice for Today: "; cin >> choice;
		
		// activity based on his choice.
		
		switch (choice){
			
			case 1: {
				
				Color(2); // green color
				
				// taking inputs -> letter to represent, steps to travel;
				char s;
				
				cout<<"\n\tEnter a letter to represent yourself : "; cin >> s;
				cout<<"You are going to a Wine shop.";
				
				int steps; 
				cout<<"How much steps you can take once for travel (enter below 4) : ";  cin >> steps;
				
				cout<<"\n\n\tYour Journey will looks like: \n\n";
				
				
				Color(30);
				
				// see the journey from home to shop
				for(int i = 0; i < distance / 2; i+=steps){
					
					// printing the path
					cout<<"|Home|";
					for(int j = 0; j < distance /2 ; j++){
						if (j == i) cout<< s ;
						else cout<<" ";
					}
					cout<<"|Shop|"<<endl;
					
					// if steps = 1 then there is no need of this condition
					if (steps != 1 && (i + steps) >= (distance / 2)){
						cout<<"|Home|";
						for(int j = 1; j <= distance /2 ; j++){
							if (j == distance/2) cout<< s ;
							else cout<<" ";
						}
						cout<<"|Shop|"<<endl;
					}
				}
				
				Color(2); // green color
				// user arrives at the wine shop
				cout<<"\n----------WINE SHOP ---------- WINE SHOP ---------- WINE SHOP ----------\n\n ";
				
				cout<<"\n\tHey ! you are feeling Throat Pain."<<endl;
				cout<<"  What you want to buy : \n\t 1. Red Wine\n\t 2. White Wine\n\t 3. Dessert Wine "<<endl;
				
				// getting the choice of user
				int x; cout<<"Enter your choice (choose wine of type 1 | 2 | 3 ) : "; cin >> x;
				
				// taking input again if user's input is not in between 1 to 3 inclusive
				if (x > 3 || x < 1) {
					while( x > 3 || x < 1){
						cout<<"Enter a valid wine type." <<endl;
						cout<<"Enter your choice again (choose wine of type 1 | 2 | 3 ) : "; cin >> x;	
					}
				}
				
				// telling the user to not drink in middle of his path. Otherwise his path will looks like (shown in display)
				cout<<"\n\n Your journey will be one of this if you take wine before reaching home.\n\n"<<endl;
				
				// assuming the user drink completely in the middle
				int current = distance / 2;
				
				Color(78);
				
				while (1){
					
					// printing the current position of the user in a path.
					cout<<"|Shop|";
					for(int j = 1; j <= distance; j++){
						if (j == current) cout<< s ;
						else cout<<" ";
					}
					cout<<"|Home|"<<endl;
					
					// moving the user from current position.
					// since he is drunk so he can either move left, curr and right from his current position representing by -1, 0 ,1 
					// move is rand() % 3 - 1 . here rand() % 3 means answer will be 0, 1, 2  and 1 is subtracted so we will get -1 as well for left movement.
					int move = rand() % 3 - 1;
					current = current + move; // current is now change based on move of user.
					
					if (current < 1) break; // if current < 1 , means user reach shop again.
					if (current >= distance) break; // if > distance means he reached home.
					
					// for delay in printing
					for (int sleep = 0; sleep < 1000000; sleep++);
				}
				
				Color(2);
				if (current < 1) cout<<"\n\t You can't reach your Home\n\n";
				else cout<<"\n\t Hey ! you will reach your home but see how you are travelling.\n\tSo, Drink it at your home\n";
					
				break;
			}			
				
			case 2:{
				
				// taking inputs -> letter to represent, steps to travel;
				char se;
				Color(2);
				cout<<"\n\tEnter a letter to represent yourself : "; cin >> se;
				cout<<"You are going to Juice shop.";
				
				int steps; 
				cout<<"How much steps you can take once for travel (enter below 4) : ";  cin >> steps;
				
				cout<<"\n\n\tYour Journey will looks like: \n\n";
				
				// printing the journey from home to shop based on steps
				Color(240);
				for(int i = 0; i < distance / 2; i+=steps){
					cout<<"|Home|";
					for(int j = 0; j < distance /2 ; j++){
						if (j == i) cout<< se ;
						else cout<<" ";
					}
					cout<<"|Shop|"<<endl;
					
					// if steps = 1 then there is no need of this condition
					if (steps != 1 && (i + steps) >= (distance / 2)){
						cout<<"|Home|";
						for(int j = 1; j <= distance /2 ; j++){
							if (j == distance/2) cout<<se;
							else cout<<" ";
						}
						cout<<"|Shop|"<<endl;
					}
				}
				
				Color(2);
				// basic functionality in shop
				cout<<"\n----------JUICE SHOP ---------- JUICE SHOP ---------- JUICE SHOP ----------\n\n ";
				
				
				cout<<"\n\tHey! you are looking for a good Health. \n\t\tWhich type of Juice You want : "<<endl;
				cout<<" 1. Orange Juice"<<endl;
				cout<<" 2. Mango Juice"<<endl;
				cout<<" 3. SugarCane Juice"<<endl;
				
				int y; cout<<"Enter your choice (choose Juice of type 1 | 2 | 3 ) : "; cin >> y; // taking user choice
				
				
				// if choice is in valid then taking input again
				if (y > 3 || y < 1) {
					while( y > 3 || y < 1){
						cout<<"Enter a valid Juice type." <<endl;
						cout<<"Enter your choice again (choose Juice of type 1 | 2 | 3 ) : "; cin >> y;	
					}					
				} 
				
				
				// aware the user by showing him journey if he drinks juice now.
				// assuming his power will increased by 2 steps
				cout<<" Your journey will be one of this if you take JUICE now.\n\n";
				
				
				// printing the path of the user.
				int current = 0;
				
				Color(224);
				
				while (current < distance){
					
					cout<<"|Shop|";
					for(int j = 0; j < distance; j++){
						if (j == current) cout << se;
						else cout<<" ";
					}
					cout<<"|Home|"<<endl;

					current = current + 2;
					
				}
				
				Color(2);
				cout<<"\n\t You have to just travel at least "<< distance / 2 <<" Steps for reaching home\n";
				break;
			}
							
			case 3:
				// this is used for exit the program
				choice = 3;
				break;
				
			default: 
				Color(206);
				cout<<"\tEnter a valid choice."<<endl;
				
		}
		
		cout<<"\n";
		
	} while( choice != 3);
	
	return 0;
}

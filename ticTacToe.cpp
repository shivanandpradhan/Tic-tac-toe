// Tic Toc game.........

#include<windows.h>
#include<bits/stdc++.h>

using namespace std;


// this is for adding color...
void Color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



// creating a row box
void createRowBox(char arr[], int i, int pos){
	
	// this condition is for coloring the box where player has currently enter his value 'X' or 'O'
	if ((arr[i] == 'X' || arr[i] == 'O') && (i == pos)) {
			Color(78);  // 78 signifies a background color of red. 
			cout<<"      "<<arr[i]<<"       |";
			Color(30);
	}
	
	// this condition is for coloring the box where player has previously enter his value 'X' or 'O'
	else if (arr[i] == 'X' || arr[i] == 'O')
		cout<<"      "<<arr[i]<<"       |";

	// other than this leave an empty box.
	else cout<<"              |";
	
}

// creating a board of tic-toe on each turn of players
void createBoard(char arr[],int pos){
	
	cout<<"\n\t";
	
	// top design of board with background as blue
	Color(30);
	cout<<"----------------------------------------------"<<endl;
	Color(2);
	
	for(int i = 0; i < 9; i+=3){
		
		// run when the position is same as i
		// this condition is for coloring the box where player has currently enter his value 'X' or 'O'
		cout<<"\t";
		
		Color(30);
		cout<<"|";
		
		createRowBox(arr, i, pos);
		
		createRowBox(arr, i+1, pos);
		
		createRowBox(arr, i+2, pos);
				
		Color(2);
		
		cout<<"\n\t";
		
		Color(30);
		cout<<"----------------------------------------------"<<endl;
		Color(2);
		
	}
	
	cout<<endl;
	Color(2);
}

// helper function  for building row of Winner's Board
void winnerHighliterRow( char arr[], int i, int l, int m, int n){
	
	// this condition is for printing the pattern of winner's 
	// if i match l, m or n, then color the background differently.
	if ((arr[i] == 'X' || arr[i] == 'O') && (i == l || i == m || i == n)){
			
			Color(30);
			cout<<"      "<<arr[i]<<"       |";
			Color(224);
			
	}
	// just print the value 
	else if (arr[i] == 'X' || arr[i] == 'O'){
		cout<<"      "<<arr[i]<<"       |";
	}
	// empty box
	else{
			cout<<"              |";
	}
	
}

// this function is again for printing the board for the winner
// that will tell why winner is winning.
// means represent the pattern he is forming. (with the help of background color)
void winningHighliter(char arr[], int l, int m, int n){
	
	cout<<"\n\t";
	
	// top design of board with background as blue
	Color(224);
	cout<<"----------------------------------------------"<<endl;
	Color(2);
	
	for(int i = 0; i < 9; i+=3){
		
		
		cout<<"\t";
		
		Color(224);
		cout<<"|";
		
		winnerHighliterRow(arr, i, l, m, n);
		
		winnerHighliterRow(arr, i+1, l, m, n);
		
		winnerHighliterRow(arr, i+2, l, m, n);
		
		Color(2);
		
		cout<<"\n\t";
		
		Color(224);
		cout<<"----------------------------------------------"<<endl;
		Color(2);
		
	}
	
	cout<<endl;
	Color(2);
}


// this condition is used for checking the winner.
// return the index of winning array which satisfies the condition of winning.
int checkWinner(int w_arr[][3], char arr[]){
	
	for (int i = 0; i < 8; i++){
		
		if (arr[w_arr[i][0]] == arr[w_arr[i][1]] && arr[w_arr[i][1]] == arr[w_arr[i][2]]) return i;
	}
	
	return -1;
}



// main function
int main(){
	
	
	
	// winning array will contain all possible pos of winning
	int winning_array[][3] = {
		{ 0, 1 , 2} , {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}
	};
	
	cout<<"\n---******----******--- Tic Tac Toe ---*******---******-----"<<endl;
	cout<<endl<<endl;
	
	int firstWin = 0, secondWin = 0;
	
	// get the names of first and second player.	
	string fst, sec, currentWinner = fst;
	cout<<"  Enter first Player Name : "; cin >> fst; cout<<endl;
	cout<<"  Enter second Player Name : "; cin >> sec;cout<<endl;
	
	string choice;	
		
	do{
		
		
		// array of 9 number will represent the board for tic toe game.
		char arr[] = {'1','2','3','4','5','6','7','8', '9'};
		
		cout<<"\n---------------------------------------------------------------------------------------------\n\n";
		
		// display the empty board.
		cout<<"\n Empty Board for playing Tic Tac Toe Game"<<endl<<endl;
		
		// background blue;
		cout<<"\t";
		
		Color(30);
		
		cout<<"--------------------------------------------"<<endl;
		
		Color(2);
		
		for(int i = 0; i < 9; i+=3){
			cout<<"\t";
			
			Color(30);
			cout<<"|     "<<arr[i]<<"      |      "<<arr[i+1]<<"       |       "<<arr[i+2]<<"      |"<<endl;
			
			Color(2);
			cout<<"\t";
			
			Color(30);
			cout<<"--------------------------------------------"<<endl;
			Color(2);
			
		}
		
		cout<<endl;
		
		// setting the color to green.
		Color(2);
				
		
		bool first, second;
		(currentWinner == fst) ? second = true, first = false : first = true, second = false;  
		
		// position variable
		int pos;
		int operation = 0;
		
		
		
		//run loop until any user wins.
		while (true){
		
			
			// run on turn of first user.
			if (first) {
				do{
					cout<<"\n\t Active Player - First : "<<fst<<endl<<endl;				
					
					cout<<"  Enter Position(1 - 9) where you want to write \'X\' : "; cin >> pos;
					cout<<endl;
					
					if (arr[pos-1] == 'X' || arr[pos-1] == 'O')
						cout<<"\n\tDon't Enter a Position where already is \'X\' or \'O\'"<<endl<<endl;
					
				}while(arr[pos-1] == 'X' || arr[pos-1] == 'O');
				
				// if arr[pos-1] is not equals to 'x' then go and replace it with 'X'
				arr[pos-1] = 'X';
				
				// now first user turn is over. 
				// give the turn to second.
				first = false;
				second = true;
			}
			
			// run on second user's turn.
			else{
				
			
				do{
					
					cout<<"\n\t Active Player - Second : "<<sec<<endl<<endl;
					
					cout<<"  Enter Position(1 - 9) where you want to write \'X\' : "; cin >> pos;
					
					cout<<endl;	
					
					if (arr[pos-1] == 'X' || arr[pos-1] == 'O')
						cout<<"\n\tDon't Enter a Position where already is \'X\' or \'O\'"<<endl<<endl;
					
				} while(arr[pos-1] == 'X' || arr[pos-1] == 'O');
				
				
				// if arr[pos-1] is not equals to 'O' then go and replace it with 'O'
				arr[pos-1] = 'O';
				
				
				// now second user turn is over.
				// give the turn to first.
				second = false;
				first = true;			
			}
			
			
			//increment the operation.
			// because we want to run this loop until all possible moves are over.
			operation++; 
			
			
			// printing the board for the user with his move.
			cout<<endl<<"  Now Board looks like :- "<<endl<<endl;
				
			createBoard(arr, pos-1);
			
			
			
			// check the winner. 
			int chk_winner = checkWinner(winning_array, arr);
			
			// if this is not equals to -1 means there is some winner 
			// where chk_winner represent the index of winning_array
			// means containing the possible moves due to which the user wins.
			if (chk_winner != -1){
				
				// printing the Winner
				cout<<"\n  ------*******---------- ******---------*******---------- ******--------"<<endl;
				cout<<"\n\t WINNER OF GAME => ";
				(first) ? currentWinner = sec : currentWinner = fst;
				
				cout<<currentWinner;
				cout<<endl;
				
				// increment the winning total of first and second user
				(first) ? secondWin++ : firstWin++;
				
				// display the winning times  of first and second.
				cout<<"\n\t"<<fst<<" wins : "<< firstWin;
				cout<<"\t"<<sec <<" wins : "<<secondWin<<endl;
				
				
				cout<<"\n  ------*******---------- ******---------*******---------- ******--------"<<endl;
				
				cout<<"\n\n\tWinner's Board :- "<<endl<<endl;
				
				// printing the board by highlighting the winning board. 
				// means representing all moves that make the user to win the game.
				winningHighliter(arr, winning_array[chk_winner][0], winning_array[chk_winner][1], winning_array[chk_winner][2]);
				
				// now we found user so break the game of tic toe game.
				break;
			}
			
			// if operation is greater than 8 then all possible move is over.
			// so print the match is draw
			// and break the loop.
			if (operation > 8){
				cout<<"Match Drawn"<<endl;
				break;
			}		
		
		}
		
		cout<<"\n Do you want to Play Again (Type \"no\" for exit):- "; cin  >> choice;
		cout<<endl;
		
	} while (choice != "no");
	
	return 0;
}

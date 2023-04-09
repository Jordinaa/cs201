#include <iostream>
#include <vector>

using namespace std;

// input of matrix size 
// then values of each element in matrix
// then same for the second 
// checks if it can be added else returns error
// checks if it can be multiplied else returns error





int main(){
	int matrix1[20][20];
	int matrix2[20][20];
	int row1, column1;
	int row2, column2;
	// quits program when q is selected
	char key = 'y';

	while (tolower(key) != 'q')
	{

		// matrix 1 input output
		cout << "enter the # of rows in matrix 1" << endl;
		cin >> row1;
		cout << "enter the # of columns in matrix 1" << endl;
		cin >> column1;
		cout << "enter the values of this matrix by entering each row at once WITH each number seperated by a space" << endl;

		for(int i = 0; i < row1; i++){
			for(int j = 0; j < column1; j++){
				cin >> matrix1[i][j];
			}
		}
		
		cout << "your first matrix" << endl;

		for(int i = 0; i < row1; i++){
			for(int j = 0; j < column1; j++){
				cout << matrix1[i][j] << " ";
			}
			cout << endl;
		}


		// matrix 2 input output
		cout << "enter the # of rows in matrix 2" << endl;
		cin >> row2;
		cout << "enter the # of columns in matrix 2" << endl;
		cin >> column2;
		cout << "enter the values of this matrix by entering each row at once WITH each number seperated by a space" << endl;

		for(int i = 0; i < row2; i++){
			for(int j = 0; j < column2; j++){
			cin >> matrix2[i][j];
			}
		}

		cout << "congrats you entered your second matrix" << endl;

		for(int i = 0; i < row2; i++){
			for(int j = 0; j < column2; j++){
				cout << matrix2[i][j] << " ";
			}
			cout << endl;
		}

		if(row1 == row2 && column1 == column2){
			cout << "matrix1 + matrix2 is: " << endl;
		
			for(int i = 0; i < row1; i++){
		
				for(int j = 0; j < column1; j++){
					cout << matrix1[i][j] + matrix2[i][j] << " ";
				}
		
				cout << endl;
			}
		}
		else{
			cout << "can't add 2 matrixes of this size together, # of columns and rows must be the same" << endl;
		}

		if(column1 == row2){
			cout << "matrix 1 * matrix 2 is:" << endl;
			for(int i = 0; i < row1; i++){
		
				for(int j = 0; j < column2; j++){
					
					int sumVal = 0;
					for(int k=0; k < column1; k++){
						sumVal += matrix1[i][k] * matrix2[k][j];
					}
					cout << sumVal << " ";
				}
				cout << endl;
			}
		}
		else{
			cout << "can't multiple 2 matrixes of this size together, the # of columns of matrix 1 should be equal to the # of rows in grid 2";
		}
		cout << "press Q to quit, or any key to do another operation" << endl;
		cin >> key;
	
	return 0;
	}
}


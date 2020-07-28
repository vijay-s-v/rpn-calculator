#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// Assume the input is always a well formed RPN expression
// Use arrays to hold the operators and operands
// Valid operators: + - * /
// Traverse through the arrays to compute the RPN expression
int main(){
	// Get expression
	cout << "> Please enter an RPN expression" << endl;
	string line;
	getline(cin, line, '\n');

	// Parse the expression into two arrays
	int n = 0;
	for(int i = 0; i < line.size(); i++){
		if(isspace(line.at(i))){ n++; }
	}

	int numOperators = n / 2;
	int numOperands = numOperators + 1;
	int operands[numOperands];
	string operators[numOperators];
	stringstream * ss = new stringstream(line);
	
	for(int i = 0; i < numOperands; i++){
		*ss >> operands[i];
	}
	for(int i = 0; i < numOperators; i++){
		*ss >> operators[i];
	}
		
	for(int i = 0; i < numOperands; i++){
		cout << operands[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < numOperators; i++){
		cout << operators[i] << " ";
	}
	cout << endl;

	/*
	// Evaluate the expression
	n = numOperands;
	int result = 0;
	for(int i = 0; i < numOperators; i++){
		switch(operators[i]){
			case '+' :
				result = operands[n - 2] + operands[n - 1];
				break;
			case '-' :
				result = operands[n - 2] - operands[n - 1];
				break;
			case '*' :
				result = operands[n - 2] * operands[n - 1];
				break;
			case '/' :
				result = operands[n - 2] / operands[n - 1];
				break;
			default :
				break;
		}
		operands[n - 2] = result;
		n--;
	}
	cout << result << endl;
	*/
}

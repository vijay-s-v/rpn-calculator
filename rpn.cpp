#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int evaluateRPN(char * operators, int * operands, int n){
	int len = n - 1;
	int result = 0;
	for(int i = 0; i < len; i++){
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
	// cout << "> " << result << endl;
	return result;
}

// Assume the input is always a well formed RPN expression
// Use arrays to hold the operators and operands
// Valid operators: + - * /
// Traverse through the arrays to compute the RPN expression
int main(){
	string line;
	cout << "> Please enter an RPN expression" << endl;
	while(true){
		// Get expression
		cout << "> ";
		getline(cin, line, '\n');
		if(line.compare("exit") == 0){ return 0; } 

		// Parse the expression into two arrays
		int n = 0;
		for(int i = 0; i < line.size(); i++){
			if(isspace(line.at(i))){ n++; }
		}	

		int numOperators = n / 2;
		int numOperands = numOperators + 1;
		int operands[numOperands];
		char operators[numOperators];
		stringstream * ss = new stringstream(line);
	
		for(int i = 0; i < numOperands; i++){
			*ss >> operands[i];
		}
		for(int i = 0; i < numOperators; i++){
			*ss >> operators[i];
		}
		
		cout << "> " << evaluateRPN(operators, operands, numOperands) << endl;
	}
}

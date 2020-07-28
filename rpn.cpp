#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

double evaluateRPN(char * operators, double * operands, int n){
	int len = n - 1;
	double result = 0;
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
				if(operands[n - 1] == 0){ return NAN; }
				result = operands[n - 2] / operands[n - 1];
				break;
			default :
				break;
		}
		operands[n - 2] = result;
		n--;
	}
	return result;
}

// Assume the input is always a well formed RPN expression
// Use arrays to hold the operators and operands
// Valid operators: + - * /
// Traverse through the arrays to compute the RPN expression
int main(){
	string line;
	string history [10];
	double memory = 0;
	cout << "> Please enter an RPN expression" << endl;
	while(true){
		// Get expression
		cout << "> ";
		getline(cin, line, '\n');
		if(line.compare("exit") == 0){ break; }
		else if(line.compare("M") == 0){
			cout << "> " << memory << endl;
			continue;
	        }

		// Parse the expression into two arrays
		int n = 0;
		for(int i = 0; i < line.size(); i++){
			if(isspace(line.at(i))){ n++; }
		}	

		int numOperators = n / 2;
		int numOperands = numOperators + 1;
		double operands[numOperands];
		char operators[numOperators];
		stringstream * ss = new stringstream(line);
	
		for(int i = 0; i < numOperands; i++){
			// Check for M character indicating to use last result as an operand
			int temp = ss->peek();
			if(!isdigit(temp) && temp == 77){
				operands[i] = memory;
				string dump;
				*ss >> dump;
				continue;
			}
			*ss >> operands[i];
		}
		for(int i = 0; i < numOperators; i++){
			*ss >> operators[i];
		}
		
		// Display result and update memory
		double result = evaluateRPN(operators, operands, numOperands);
		cout << "> " << result << endl;
		memory = result;
		delete ss;
	}
	return 0;
}

#include <string>
#include <iostream>

using namespace std;

// Assume the input is always a well formed RPN expression
// Use arrays to hold the operators and operands
// Valid operators: + - * /
// Traverse through the arrays to compute the RPN expression
int main(){
	// Proof of concept
	// Compute 3 4 5 * -
	// Result should be -17
	int operands [3] = {3, 4, 5};
	char operators [2] = {'*', '-'};

	// Evaluate the expression
	int n = sizeof(operands) / sizeof(operands[0]);
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
	cout << result << endl;
}

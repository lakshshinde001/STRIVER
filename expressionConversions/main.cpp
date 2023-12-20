#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int prec(char c){
	if(c == '+' || c == '-'){
		return 1;
	}else if(c == '*' || c == '/'){
		return 2;
	}else if(c == '^'){
		return 3;
	}else {
		return -1;
	}
}
void infixToPostfix(string exp){
	stack<char> st;
	string result;
	
	for(int i=0; i<exp.length(); i++){
		char c = exp[i];
		if((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			result += c;		
		}else if(c == '('){
			st.push('(');
		}else if(c == ')'){
			while(!st.empty() && st.top() != '('){
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && prec(exp[i]) <= prec(st.top())){
				result += st.top();
				st.pop();
			}
			st.push(c);
		}	
	}
	while(!st.empty()){
			result += st.top();
			st.pop();
		}	
	cout<<"\nPostfix of infix = "<<result;
}

int main(){
	string expression = "a+b";
	infixToPostfix(expression);
	return 0;
}

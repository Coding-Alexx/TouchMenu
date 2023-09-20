#include <stack>


int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

const char* umwandeln(const char* s) {
    std::string str = s;
    str = "(" + str + ")";
    std::stack<char> numbers;
    std::stack<char> operators;
    std::string returnText = "";

    for (char c : str) {
        if (isdigit(c) || c == '.') {
            // Check for multi-digit numbers
            std::string numStr = "";
            while (isdigit(c) || c == '.') {
                numStr += c;
                c = str[str.find(c) + 1];
            }
            returnText += numStr + " ";
            continue;
        }

        if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                returnText += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                returnText += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    return returnText.c_str();
}

float calculateOp(float operand1, char op, float operand2) {
  if (op == '+') {
    return operand1 + operand2;
  } else if (op == '-') {
    return operand1 - operand2;
  } else if (op == '*') {
    return operand1 * operand2;
  } else if (op == '/') {
    return operand1 / operand2;
  }
  return 0.0;  // Standardrückgabe, falls der Operator unbekannt ist
}

String umwandelnUndBerechnen(String str) {
    str = "(" + str + ")";
    std::stack<char> opStack;
    std::vector<float> numStack;
  
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ')') {
            float num = 0;
            // bool negativ = false;
            // if (i+1 < str.length() && str[i] == '-' && isDigit(str[i+1])) {
            //     negativ = true;
            //     i++;
            // }
            while (isDigit(str[i])) {
                num = num * 10 + float(str[i] - '0');
                if (i+1 < str.length()) i++;
            }
            if (num > 0) {
                // if (negativ) num * -1;
                numStack.push_back(num);
                LOGGER(num)
            } 
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                opStack.push(str[i]);
                LOGGER(opStack.top())
            }

        } else {
            while (!opStack.empty()) {
                char op = opStack.top();
                opStack.pop();
                if (op != '(') {
                    if (numStack.size() < 2) {
                        // Fehler: Nicht genügend Operanden für den Operator
                        LOGGER_ERROR(numStack.size())
                        return "Fehler: Ungültiger Ausdruck";
                    }
                    float operand2 = numStack.back();
                    numStack.pop_back();
                    float operand1 = numStack.back();
                    numStack.pop_back();
                    float result = calculateOp(operand1, op, operand2);
                    LOGGER_PATTERN("_ _ _ = _", operand1, op, operand2, result)
                    numStack.push_back(result);
                } else {
                    break;
                }
            }
        }
    }
  
    if (numStack.size() == 1) {
        return String(numStack[0]);
    } else {
        // Fehler: Unvollständiger Ausdruck
        LOGGER_ERROR("Ungültig!")
        return "Fehler: Ungültiger Ausdruck";
    }
}

double returnOP(string& word,vector<string>&strarr,int& i)
{
    double num1,num2;
    // using MACROS if required
    if(strarr[i+1].compare("e")==0)  num1=e;
    if(strarr[i+1].compare("pi")==0) num1=pi;
    else                             num1=stof(strarr[i+1]);
     
    if(strarr[i+2].compare("e")==0)  num2=e;
    if(strarr[i+2].compare("pi")==0) num2=pi;
    else                             num2=stof(strarr[i+2]);
    
    double degree=pi*num1/180;
     
     // library of functions to calculate result
      // after finding the 'type of operation'
    if(word.compare("+")==0)           return num1+num2;
    else if(word.compare("-")==0) return num1-num2;
    else if(word.compare("*")==0) return num1*num2;
    else if(word.compare("/")==0)   return num1/num2;
    else if(word.compare("%")==0)  return (num2/num1)*100;
     
    else if(word.compare("log")==0)      return log(num1)/log(num2);
    else if(word.compare("exp")==0)      return pow(num1,num2);
    else if(word.compare("sqrt")==0)     return sqrt(num1);
    else if(word.compare("cbrt")==0)     return cbrt(num1);
    
    else if(word.compare("sin")==0)      return sin(num1);
    else if(word.compare("cos")==0)      return cos(num1);
    else if(word.compare("tan")==0)      return tan(num1);
    else if(word.compare("sec")==0)      return 1/cos(num1);
    else if(word.compare("cosec")==0)    return 1/sin(num1);
    else if(word.compare("cot")==0)      return 1/tan(num1);
     
    else if(word.compare("sindeg")==0)   return sin(degree);
    else if(word.compare("cosdeg")==0)   return cos(degree);
    else if(word.compare("tandeg")==0)   return tan(degree);
    else if(word.compare("secdeg")==0)   return 1/cos(degree);
    else if(word.compare("cosecdeg")==0) return 1/sin(degree);
    else if(word.compare("cotdeg")==0)   return 1/tan(degree);
     
    else if(word.compare("sininv")==0)   return asin(num1);
    else if(word.compare("cosinv")==0)   return acos(num1);
    else if(word.compare("taninv")==0)   return atan(num1);
    else if(word.compare("secinv")==0)   return acos(1/num1);
    else if(word.compare("cosecinv")==0) return asin(1/num1);
    else if(word.compare("cotinv")==0)   return atan(1/num1);
     
    else if(word.compare("sininvdeg")==0)return 180*asin(num1)/pi;
    else if(word.compare("cosinvdeg")==0)return 180*acos(num1)/pi;
    else if(word.compare("taninvdeg")==0)return 180*atan(num1)/pi;
    else if(word.compare("secinvdeg")==0)return 180*acos(1/num1)/pi;
    else if(word.compare("cosecinvdeg")==0)return 180*asin(1/num1)/pi;
    else if(word.compare("cotinvdeg")==0)return 180*atan(1/num1)/pi;
     
    return -1;
}
 
// function for fetching each word from a string array of operations
// and pushing them into result after performing required operation
vector<double>processOperations(string& operations) {
    string word;
    vector<string>strarr;
    vector<double>result;
    
  // stringstream class to extract
  // word from string
    stringstream ss(operations);
    while(ss>>word)
    strarr.push_back(word);
     
  // passing each third word to returnOP
  // to calculate final result of that query
    for(int i=0;i<strarr.size();i+=3)
    result.push_back(returnOP(strarr[i],strarr,i));
    
    return result;
}

#include <math.h>

#include <iostream>
#include <stack>
#include <vector>

class PolishNotation {
   private:
        std::string operations[5] = {"+", "-", "*", "/", "^"};
        bool isDigit(char &ch) const { return ch >= '0' && ch <= '9'; }

        bool isOperation(std::string str) const {
            for (std::string x : operations) {
                if (str == x) return 1;
            }
            return 0;
        }

        bool isNumber(std::string str) const {
            bool floatingPoint = 0;
            if (str.length() == 1) {
                return isDigit(str[0]);
            }
            for (int i = (str[0] == '-'); i < str.length(); i++) {
                if (!floatingPoint && str[i] == '.') {
                    floatingPoint = 1;
                    continue;
                }
                if (!isDigit(str[i])) return 0;
            }
            return 1;
        }

        bool isHigher(std::string a, std::string b) const {
            int cnt1 = 0, cnt2 = 0;
            cnt1 = (a == "+" || a == "-" ? 1 : a == "*" || a == "/" ? 2 : 3);
            cnt2 = (b == "+" || b == "-" ? 1 : b == "*" || b == "/" ? 2 : 3);
            return cnt1 > cnt2;
        }

        std::string calculate(std::string a, std::string b, std::string operation) const {
            long double x = stold(a);
            long double y = stold(b);
            if (operation == "+") return std::to_string(x + y);
            if (operation == "-") return std::to_string(x - y);
            if (operation == "*") return std::to_string(x * y);
            if (operation == "/") return std::to_string(x / y);
            if (operation == "^") return std::to_string(pow(x, y));
            return a;
        }

        std::vector<std::string> cutter(std::string str) const {
            std::vector<std::string> ope;
            std::string tmp = "";
            int ind = 0;

            while (ind < str.length()) {
                while (ind < str.length() &&
                       (isDigit(str[ind]) || str[ind] == '.')) {
                    tmp += str[ind++];
                }

                if (tmp != "") {
                    ope.push_back(tmp);
                    tmp = "";
                }

                while (ind < str.length() && !isDigit(str[ind])) {
                    tmp += str[ind++];
                }

                if (tmp.length() > 1 && tmp.back() == '-') {
                    tmp.pop_back();
                    ope.back() = "-" + ope.back();
                }

                if (tmp != "") {
                    ope.push_back(tmp);
                    tmp = "";
                }
            }
            return ope;
        }

        std::vector<std::string> convertToPolishNotation(std::vector<std::string> ope) const {
            if (ope.size() == 1) return {ope[0]};
            std::vector<std::string> a;
            a.push_back(ope[0]);
            std::stack<std::string> st;
            for (int i = 1; i < ope.size(); i += 2) {
                if (st.empty()) {
                    st.push(ope[i]);
                } else {
                    while (!st.empty() && !isHigher(ope[i], st.top())) {
                        a.push_back(st.top());
                        st.pop();
                    }
                    st.push(ope[i]);
                }
                a.push_back(ope[i + 1]);
            }
            while (!st.empty()) {
                a.push_back(st.top());
                st.pop();
            }
            return a;
        }

   public:
        std::vector<std::string> convertToPolishNotation(std::string str) const {
            return convertToPolishNotation(cutter(str));
        }

        long double calculateThePolishNotation(std::vector<std::string> a) const {
            int ind = 0;
            std::stack<std::string> st;
            while (ind < a.size()) {
                while (st.empty() || isNumber(st.top())) {
                    st.push(a[ind++]);
                }
                std::string operation = st.top();
                st.pop();
                std::string x = st.top();
                st.pop();
                std::string y = st.top();
                st.pop();
                st.push(calculate(y, x, operation));
            }
            return stold(st.top());
        }
};
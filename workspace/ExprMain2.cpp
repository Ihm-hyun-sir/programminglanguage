#include <iostream>
#include <list>
#include <string>

#include "antlr4-cpp/ExprBaseListener.h"
#include "antlr4-cpp/ExprLexer.h"
#include "antlr4-cpp/ExprParser.h"



using namespace std;
using namespace antlr4;
using namespace antlr4::tree;







class ErrorHandler : public BaseErrorListener {
	virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
      const std::string &msg, std::exception_ptr e)
	{ cout << "Invalid Syntax ! \n";}

    virtual void reportAmbiguity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact,
      const antlrcpp::BitSet &ambigAlts, atn::ATNConfigSet *configs)
     {cout << "Invalid Syntax ! \n";}

    virtual void reportAttemptingFullContext(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
      const antlrcpp::BitSet &conflictingAlts, atn::ATNConfigSet *configs)
    {cout << "Invalid Syntax ! \n";}

    virtual void reportContextSensitivity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
      size_t prediction, atn::ATNConfigSet *configs)
    {cout << "Invalid Syntax ! \n";}	    


};



class EvalListener : public ExprBaseListener {
public:
	list<string> numbers;
	stack<string> op;
	int op_for_variable = 0;
	string op_for_variable_s = "";
	//for assn
	map< string, string> vars;
	bool is_assning = false;
	string id;
	

	virtual void enterProg(ExprParser::ProgContext *ctx) {
	//	cout << "enterProg: \n";
	}
	virtual void exitProg(ExprParser::ProgContext *ctx) {
	//	cout << "exitProg: \n";
	//	printlist();
	}
	  virtual void enterAssn(ExprParser::AssnContext *actx )  {
        //        cout << "\tenter Assn: \n";
                is_assning = true;
        }
          virtual void exitAssn(ExprParser::AssnContext *actx ) {
        //        cout << "\texit Assn: \n";
        }
	virtual void enterExpr(ExprParser::ExprContext *ctx) {
	//	cout << "\tenterExpr: \n";
	}
	virtual void exitExpr(ExprParser::ExprContext *ctx) {
	//	cout << "\texitExpr: \n";
	}
	  virtual void enterMulexpr(ExprParser::MulexprContext *mctx ) {
	//	cout << "\tenterMulExpr: \n";
 	}
	  virtual void exitMulexpr(ExprParser::MulexprContext *mctx ) {
	//	cout << "\texitMulExpr: \n";
 	}
	  virtual void enterBarexpr(ExprParser::BarexprContext *bctx )  {
	//	cout << "\tenterBarExpr: \n";
		
	}
	  virtual void exitBarexpr(ExprParser::BarexprContext *bctx ) {
	//	cout << "\texitBarExpr: \n";
		if(bctx->op())
		{
			if(is_assning)
			{
				if(bctx->op()->MINUS())
                                {
                                        vars[id] = "-"+vars[id];
                                }
			}
			else{
				if(bctx->op()->MINUS())
				{
					numbers.push_back("-1");
					numbers.push_back("*");
				}
				else if(bctx->op()->PLUS())
				{
					numbers.push_back("1");
					numbers.push_back("*");
				}
			}
		}
	}
	  virtual void enterOp(ExprParser::OpContext *octx )  {
	//	cout << "\tenter Op: \n";
		op_for_variable = 1;
	  } 
	  virtual void exitOp(ExprParser::OpContext *octx )  {
	//	cout << "\texit Op: \n";
		op_for_variable = 0;
	}		
	  virtual void enterNum(ExprParser::NumContext *nctx )  {
	//	cout << "\tenter Num: \n";
	}
	  virtual void exitNum(ExprParser::NumContext *nctx )  {
	//	cout << "\texit Num: \n";
	}
	virtual void visitTerminal(tree::TerminalNode *node) {
	//	cout << "\t\tTerminal: " << node->getText() << "\n";
		if(!op_for_variable)
		{
			prefix(node->getText() , node->getSymbol()->getType());
			op_for_variable = 0;
		}
	}
	virtual void visitErrorNode(antlr4::tree::ErrorNode *node){
		cout << "\t\t Error ! Invalid Syntax \n";
		exit(0);
       	}
	void printlist()
	{
		list<string>::iterator iter = numbers.begin();
		for(iter = numbers.begin() ; iter != numbers.end() ; iter++)
			cout << *iter << "\n";
	}

	// NEWLINE = 1, SEMI = 2, EQUAL = 3, PLUS = 4, MINUS = 5, MUL = 6, DIV = 7,
	//    LBAR = 8, RBAR = 9, INT = 10, REAL = 11, ID = 12, WS = 13
	void prefix(string text , int type)
	{
	//	cout << "/t text : " << text << "\n";
		switch(type)
		{
			case 2://SEMICOLON
				while(!op.empty())
				{
					numbers.push_back(op.top());
					op.pop();
				}
				if(is_assning)
				{
					is_assning = false;
					break;
				}
				numbers.push_back("SEMICOLON");
				break;
			case 4 :// +
				while(!op.empty()  && op.top() != "(")
				{
					numbers.push_back(op.top());
					op.pop();
				}
				op.push(text);
				break;
			case 5 :// -
				while(!op.empty() && op.top() != "(")
                                {
                                        numbers.push_back(op.top());
                                        op.pop();
                                }
				op.push(text);
				break;
			case 6 :// *
				if(!op.empty())
				{
					if( op.top() == "*" || op.top() == "/" )
					{
						numbers.push_back(op.top());
						op.pop();
					}
				}
                                op.push(text);
				break;
			case 7 :// /
				if(!op.empty())
				{
					if(op.top() == "*" || op.top() == "/")
                                	{
                                        	numbers.push_back(op.top());
                                        	op.pop();
                                	}
				}
				op.push(text);
				break;
			case 8 :// (
				op.push(text);
				break;
			case 9 :// ) 
				while(!op.empty() && op.top() != "(" )
				{
					numbers.push_back(op.top());
					op.pop();
				}
				op.pop();
				break;
			case 10:// INT
				if(is_assning)
				{
					if(vars.find(id) == vars.end())
                                                vars.insert({id,text});
                                        else
                                                vars[id] = text;
					break;
				}
				numbers.push_back(text);
				break;
			case 11:// REAL
				if(is_assning)
                                {
					if(vars.find(id) == vars.end())
                                        	vars.insert({id,text});
					else
						vars[id] = text;
                                        break;
                      		}
				numbers.push_back(text);
				break;
			case 12:// ID
				if(is_assning)
                                {
                                        id = text;
                                        break;
                                }
				else if(vars.find(text) == vars.end())
				{
					cout << "Invalid syntax! \n ";
					exit(0);
				}	
				string number = vars[text];
				numbers.push_back(number);
				break;
		}
	}
	void calculator()
	{
		stack<double> numStack;
		double num1;
		double num2;
		list<double> answers;
		string symbol;
		while(numbers.size())
		{
			symbol = numbers.front();
			numbers.pop_front();
			if(symbol == "+")
			{
				if(numStack.size() < 2)
				{ cout << "Invalid syntax ! \n"; exit(0);}				
				num1 = numStack.top();
				numStack.pop();
				num2 = numStack.top();
				numStack.pop();
				numStack.push(num2+num1);
			}
			else if(symbol == "-")
			{
				if(numStack.size() < 2)
                                { cout << "Invalid syntax ! \n"; exit(0);}
				num1 = numStack.top();
                       		numStack.pop();
                               	num2 = numStack.top();
                               	numStack.pop();
                               	numStack.push(num2-num1);
			}
			else if(symbol == "*")
			{
				
				if(numStack.size() < 2)
                                { cout << "Invalid syntax ! \n"; exit(0);}
				num1 = numStack.top();
                       	       	numStack.pop();
                           	num2 = numStack.top();
                                numStack.pop();
                                numStack.push(num2*num1);
			}
			else if(symbol == "/")
			{
				if(numStack.size() < 2)
                                { cout << "Invalid syntax ! \n"; exit(0);}
				num1 = numStack.top();
                                numStack.pop();
                                num2 = numStack.top();
                                numStack.pop();
                                numStack.push(num2/num1);
			}
			else if(symbol == "SEMICOLON")
			{
				if(numStack.size() < 1)
				{
					cout << "Invalid syntax ! \n" ;
				      	exit(0);
				}
				answers.push_back(numStack.top());
				numStack.pop();
			}
			else
			{
				numStack.push(stod(symbol));
			}
			
		}
		list<double>::iterator iter = answers.begin();
                for(iter ; iter != answers.end()  ; iter++)
                        cout <<   *iter << "\n";
	}
};



int main(int argc, const char* argv[]) {
	if (argc < 2) {
		cerr << "[Usage] " << argv[0] << "  <input-file>\n";
		exit(0);
	}
	std::ifstream stream;
	stream.open(argv[1]);
	if (stream.fail()) {
		cerr << argv[1] << " : file open fail\n";
		exit(0);
	}

	cout << "---Expression Evaluation with ANTLR listener---\n";
	ANTLRInputStream input(stream);
	ExprLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ExprParser parser(&tokens);	

	ParseTreeWalker walker;
	EvalListener listener;	

	walker.walk(&listener, parser.prog());
	listener.calculator();
}

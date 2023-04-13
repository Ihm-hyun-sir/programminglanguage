#include <iostream>
#include <list>
#include <string>
#include<vector>
#include<algorithm>
#include "antlr4-cpp/ExprBaseListener.h"
#include "antlr4-cpp/ExprLexer.h"
#include "antlr4-cpp/ExprParser.h"



using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

class EvalListener : public ExprBaseListener {
public:
	stack<string> terminals;
	stack<string> operators;
	map< string, string> vars;
	bool is_op = false;
	bool is_assn=false;
	
	void print_stack()
	{
		vector<string> v;
		stack<string> answers;
		while(!terminals.empty())
		{
			v.push_back(terminals.top());
			terminals.pop();
		}
		reverse(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++){
			cout << v[i] << '\n';
		}
		return;
	}
	void calculate(int ops)
	{
		string op;
		stack<string> temp_terminals;
        	stack<string> temp_operators;
		for(int i = 0; i < ops; i++)
		{
			temp_terminals.push(terminals.top());
			temp_operators.push(operators.top());
			terminals.pop();
			operators.pop();
		}
		temp_terminals.push(terminals.top());
		terminals.pop();
		double num1;
		double num2;
		for(int i = 0; i < ops ; i++)
		{
			op = temp_operators.top();
			temp_operators.pop();
			num1 = stod(temp_terminals.top());
			temp_terminals.pop();
			num2 = stod(temp_terminals.top());
			temp_terminals.pop();
			if(op == "+") temp_terminals.push(to_string(num1+num2));
			if(op == "-") temp_terminals.push(to_string(num1-num2));
			if(op == "*") temp_terminals.push(to_string(num1*num2));
			if(op == "/") temp_terminals.push(to_string(num1/num2));
		}
		terminals.push(temp_terminals.top());
	}
	virtual void enterProg(ExprParser::ProgContext *ctx) {
	//	cout << "enterProg: \n";
		if(ctx->children.size() == 0 )
		{
			cout << "Invalid Syntax! \n";
			exit(0);
		}
	}
	virtual void exitProg(ExprParser::ProgContext *ctx) {
	//	cout << "exitProg: \n";
		print_stack();
	}
	  virtual void enterAssn(ExprParser::AssnContext *ctx )  {
          //      cout << "\tenter Assn: \n";
		is_assn = true;
        }
          virtual void exitAssn(ExprParser::AssnContext *ctx ) {
          //      cout << "\texit Assn: \n";
		string id = ctx->ID()->getText();
		string number = ctx->num()->getText();
		if(ctx->children.size() > 3)
		{
			number = ctx->op()->getText() + number;
		}
		if(vars.find(ctx->ID()->getText()) == vars.end())
		{
			vars.insert({id, ""});
		}
		vars.at(id) = number;
		is_assn = false;
        }
	virtual void enterExpr(ExprParser::ExprContext *ctx) {
	//	cout << "\tenterExpr: \n";
	}
	virtual void exitExpr(ExprParser::ExprContext *ctx) {
	//	cout << "\texitExpr: \n";
		if(ctx->children.size() > 1)
                        calculate(ctx->children.size()/2);
	}
	  virtual void enterMulexpr(ExprParser::MulexprContext *mctx ) {
	//	cout << "\tenterMulExpr: \n";
 	}
	  virtual void exitMulexpr(ExprParser::MulexprContext *ctx ) {
	//	cout << "\texitMulExpr: \n";
		if(ctx->children.size() > 1)
			calculate(ctx->children.size()/2);
 	}
	  virtual void enterBarexpr(ExprParser::BarexprContext *ctx )  {
	//	cout << "\tenterBarExpr: \n";
	}
	  virtual void exitBarexpr(ExprParser::BarexprContext *ctx ) {
	//	  cout << "exitBarexpr : \n";
		  string number;
		  string op;
		  if(ctx->op() && ctx->op()->getText() == "-")
		  {
			number = terminals.top();
			terminals.pop();
			terminals.push(to_string(-1*stod(number)));
		  }
	  }
	  virtual void enterOp(ExprParser::OpContext *octx )  {
	//	cout << "\tenter Op: \n";
		is_op=true;
	  } 
	  virtual void exitOp(ExprParser::OpContext *octx )  {
	//	cout << "\texit Op: \n";
		is_op=false;
	}		
	  virtual void enterNum(ExprParser::NumContext *nctx )  {
	//	cout << "\tenter Num: \n";
	}
	  virtual void exitNum(ExprParser::NumContext *nctx )  {
	//	cout << "\texit Num: \n";
	}
	virtual void visitTerminal(tree::TerminalNode *node) {
	//	cout << "\t\tTerminal: " << node->getText() << "\n";
		int type = node->getSymbol()->getType();
		if(is_op || is_assn)
			return;
		if(type == 12)
		{
			string id = node->getText();
			terminals.push(vars.at(id));
		}
		else if(type == 10 || type == 11)
		{
			terminals.push(node->getText());
		}
		else if(type >= 4 && type <= 7)
		{
			operators.push(node->getText());
		}
	}
	virtual void visitErrorNode(antlr4::tree::ErrorNode *node){
		cout << "\t\t Invalid Syntax \n";
		exit(0);
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
}

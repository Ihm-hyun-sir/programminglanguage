// B2CMain.cpp
#include <iostream>
#include <map>
#include <stack>
#include "antlr4-runtime.h"
#include "antlr4-cpp/BBaseVisitor.h"
#include "antlr4-cpp/BLexer.h"
#include "antlr4-cpp/BParser.h"

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;

map<string,string> symbol_table;
class TypeAnalysisVisitor : public BBaseVisitor {
public:
   // Building symbol tables,
   // infer types for 'auto' variables and functions
   // ...
 //  map<string,string> symbol_table;
   string current_var;
   string current_scope;
   string constant_type;
   string expression_var;
   string expression_type;
   string expr_type;
   string compare_type;
   string return_type;
   string atom_type;
   int* parent_addr;
   void print_map()
   {
	   cout << "symbol table \n";
	   for(map<string,string>::iterator it = symbol_table.begin(); it != symbol_table.end(); it++)
        {
		cout << "name : " + it->first + " type : " + it->second +"\n";
        }
   }
   any visitProgram(BParser::ProgramContext *ctx) override {
        // Perform some actions when visiting the program
        symbol_table.insert({"main_main","int"});
        for (int i=0; i< ctx->children.size(); i++) {
            visit(ctx->children[i]);
        }
        return nullptr;
    }
   any visitAutostmt(BParser::AutostmtContext *ctx) override{
   	int num_of_names = ctx->name().size();
	int num_of_children = ctx->children.size();
	bool assign = false;
	for(int i = 0; i < ctx->children.size() ; i++)
	{
		parent_addr = (int*)ctx;
		visit(ctx->children[i]);
	}
	return NULL;
   }
   any visitConstant(BParser::ConstantContext *ctx) override {
        	string type;
        	if(ctx -> INT())
                	type = "int";
        	if(ctx -> REAL())
                	type = "double";
        	if(ctx -> STRING())
                	type = "string";
        	if(ctx -> BOOL())
                	type = "bool";
        	if(ctx -> CHAR())
                	type = "char";
		constant_type = type;
		if(parent_addr == (int*)ctx->parent)
		{
        		symbol_table[current_var+"_"+current_scope] = constant_type;
		}
        return nullptr;
   }
   any visitName(BParser::NameContext *ctx) override {
	current_var = ctx->NAME()->getText();
	if(symbol_table.find(current_var+"_"+current_scope) == symbol_table.end())
		symbol_table.insert({current_var+"_"+current_scope,"NONE"});
	compare_type = symbol_table[current_var+"_"+current_scope];
        return nullptr;
    }
   any visitExpression(BParser::ExpressionContext *ctx) override {
        if (ctx->ASSN()) { // assignment
			visit(ctx->name());
			expression_var = current_var;
			expression_type = symbol_table[current_var+"_"+current_scope];
			string save_expression_type = expression_type;
              	expr_type = "";
	        compare_type = "";	
		visit(ctx->expr());
		expression_type = save_expression_type;
		if(expression_type == "NONE")
		{
			symbol_table[expression_var+"_"+current_scope] = expr_type;
		}
		else if(expression_type != expr_type)
		{
			throw runtime_error("expression type not matched expected : "+expression_type+" get : "+expr_type);
		}
		expression_type = "";
		compare_type = "";
		expr_type = "";
	}
	else
	{
		compare_type = "";
		expr_type = "";
		visit(ctx->expr());
		atom_type = expr_type;
		if(ctx->parent->getText().find("return") != string::npos)
		{
          //            cout<<"this is child of returnstmt expr type : " << expr_type << "\n";
			return_type = expr_type;
		}
		expression_type = "";
                compare_type = "";
                expr_type = "";
	}
        return nullptr;
    }	
   any visitExpr(BParser::ExprContext *ctx) override {
   	   if(ctx->expr().size() == 2)
	   {
	//	   cout << "two exprs \n";
		   expr_type = "";
		   compare_type = "";
		   visit(ctx->expr(0));
		   visit(ctx->expr(1));
		   if(compare_type != expr_type)
		   {
			throw runtime_error("expr type not matched expected : "+expr_type+" get : "+compare_type);
	//		cout << "type error at expr expected type : " << expr_type << " come : " << compare_type << "\n";
		   }
	   	   if(ctx->GT() || ctx->GTE() || ctx->LT() || ctx->LTE() || ctx->EQ() || ctx->NEQ())
		   {
			   expr_type = "bool";
		   }
		   compare_type = "";	   
	   }
	   else if(ctx->expr().size() == 3)
	   {
		   string temp_type;
		   expr_type = "";
		   compare_type = "";
		   visit(ctx->expr(0));
		   if(expr_type == "bool")
		   {
			   expr_type = "";
			   compare_type = "";
			   visit(ctx->expr(1));
			   temp_type = expr_type;
			   expr_type = "";
			   compare_type = "";
			   visit(ctx->expr(2));
			   if(temp_type != expr_type)
				   throw runtime_error("tenary expr type not matched expected : "+temp_type+" get : "+compare_type);
		   }
		   else
		   {
			temp_type = expr_type;
			expr_type = "";
                        compare_type = "";
                        visit(ctx->expr(1));
			if(temp_type != expr_type)
				throw runtime_error("tenary expr type not matched expected : "+temp_type+" get : "+compare_type);
			expr_type = "";
                        compare_type = "";
                        visit(ctx->expr(2));
		   }
                  if(temp_type != expr_type){
				throw runtime_error("tenary expr type not matched expected : "+temp_type+" get : "+compare_type);
		  }
	   }
	   else if(ctx->atom())
		   visit(ctx->atom());
	   return nullptr;
   }
   any visitAtom(BParser::AtomContext *ctx) override {
   	if(ctx->name())
	{
		visit(ctx->name());
		if(expr_type == "")
			expr_type = symbol_table[current_var+"_"+current_scope];
		else
			compare_type = symbol_table[current_var+"_"+current_scope];
	//	cout << "var: " << current_var << " type : " << symbol_table[current_var] << "\n";
	}
	if(ctx->constant())
	{
		visit(ctx->constant());
		if(expr_type == "")
                        expr_type = constant_type;
		else
			compare_type = constant_type;
	}
	if(ctx->expression())
	{
		visit(ctx->expression());
		expr_type = atom_type;
	}
	if(ctx->funcinvocation())
	{
		visit(ctx->funcinvocation());
	}
	return nullptr;
   }
   any visitDeclstmt(BParser::DeclstmtContext *ctx) override{
	   current_scope = ctx->name()->getText();
	   symbol_table.insert({ctx->name()->getText()+"_"+current_scope,"F_NONE"});
	   for(int i = 1; i < ctx->AUTO().size() ; i++)
	   {
		   symbol_table.insert({ctx->name()->getText() + to_string(i-1)+"_"+current_scope  ,"NONE"});
	   	   //cout << "func define " << ctx->name()->getText() << " parm : " << ctx->name()->getText() + to_string(i-1) << "\n";
	   }
           return nullptr;
   }
   any visitReturnstmt(BParser::ReturnstmtContext *ctx) override{
	   if(ctx->expression())
	   {
	//	   cout << "return stmt " << ctx->getText() << "\n";
		   visit(ctx->expression());
	   }
	   return nullptr;
   }
   any visitFuncdef(BParser::FuncdefContext *ctx) override{
	   current_scope = ctx->name(0)->getText();
   	   visit(ctx->statement());
	   symbol_table[ctx->name(0)->getText()+"_"+current_scope] = return_type;
	   if(ctx->name(0)->getText() == "main" && symbol_table["main_main"] != "int")
	   {
		throw runtime_error("func type not matched expected : int get : "+return_type);
		symbol_table["main_main"] = "int";
	   }
	   //cout << "func " << ctx->name(0)->getText() << " get type " << return_type << "\n";
	   return nullptr;
   }

  any visitFuncinvocation(BParser::FuncinvocationContext *ctx) override {
	string save_expr_type = expr_type;
	string save_compare_type = compare_type;
	string function_name = ctx->name()->getText();
	for(int i = 0 ; i < ctx->expr().size() ; i++)
	{
		expr_type = "";
		compare_type = "";
		visit(ctx->expr(i));
		if(symbol_table[function_name+to_string(i)+"_"+function_name] == "NONE")
		{
			symbol_table[function_name+to_string(i)+"_"+function_name] = expr_type;
		}
		if(symbol_table[function_name+ to_string(i)+"_"+function_name] != expr_type)
		{			
			throw runtime_error("func parameter expr type not matched expected : "+symbol_table[ctx->name()->getText() + to_string(i)+"_"+current_scope]+" get : "+expr_type);
		}	
	}
	expr_type = save_expr_type;
	compare_type = save_compare_type;
	if(expr_type == "")
                expr_type = symbol_table[function_name+"_"+function_name];
        else
                compare_type = symbol_table[function_name+"_"+function_name];
	return nullptr;	
  }
 };

class TypeAugmentationVisitor : public BBaseVisitor {
public:
   // Replace 'auto' in parse tree with inferred types
   // ...
};

class PrintTreeVisitor : public BBaseVisitor {
	string current_scope;
public:
    any visitProgram(BParser::ProgramContext *ctx) override {
    	// Perform some actions when visiting the program
	////cout << "\n\n\n\n";
	for(map<string,string>::iterator it = symbol_table.begin(); it != symbol_table.end(); it++)
	{
		if(it->second == "NONE")
		{
			throw runtime_error("Variable Type Undefined  : "+it->first+"\n");
		}
	}
    	for (int i=0; i< ctx->children.size(); i++) {
      	    visit(ctx->children[i]);
    	}
    	return nullptr;
    }

    any visitDefinition(BParser::DefinitionContext *ctx) override {
	visit(ctx->children[0]);
        return nullptr;
    }

    any visitFuncdef(BParser::FuncdefContext *ctx) override {
		// Handle function definition
        string functionName = ctx->name(0)->getText();
	current_scope = functionName;
		cout << symbol_table[ctx->name(0)->getText()+"_"+current_scope] << " " << functionName << "(" ;
        // You can retrieve and visit the parameter list using ctx->name(i)
		for (int i=0; i < ctx->name().size()-1; i++) {
			cout << symbol_table[ctx->name(0)->getText()+to_string(i)+"_"+current_scope] << " " <<ctx->name(i+1)->getText() << " ";
			if(i != ctx->name().size()-2)
				cout << ", ";		
		}
		cout << ")";

		// visit statement
		visit(ctx->statement());
        return nullptr;
    }

    any visitStatement(BParser::StatementContext *ctx) override {
		visit(ctx->children[0]);
        return nullptr;
    }

    any visitAutostmt(BParser::AutostmtContext *ctx) override {
    	// You can retrieve the variable names and constants using ctx->name(i) and ctx->constant(i)
		string type = symbol_table[ctx->name(0)->getText()+"_"+current_scope];	
	        string item;
		bool first_var = true;
		cout << type << " ";
		for (int i=1; i < ctx->children.size(); i++) {
		       item =  ctx->children[i]->getText();
		       if(item == "," || item == ";")
			{
				continue;
			}
		       else if(item == "="){
		       		cout << " = " << ctx->children[i+1]->getText() << " ";
				i++;
				continue;
		       }
		       else 
		       {
			       if(item == "auto")
				       continue;
			       if(type != symbol_table[item+"_"+current_scope])
			       {
				       cout << ";";
				       type = symbol_table[item+"_"+current_scope];
				       cout << "\n" << type << " " << item;
			       }
			       else
			       {
			       	 if(first_var)
				 {
					 cout << item << " ";
					 first_var = false;
				 }
				 else
				 {
					 cout << ", " << item << " ";
				 }		 
			       }
		       }
		}
		cout << ";" << "\n";
    	return nullptr;
    }

    any visitDeclstmt(BParser::DeclstmtContext *ctx) override {
		// Handle function declaration
        string functionName = ctx->name()->getText();
	current_scope = functionName;
		cout << symbol_table[functionName+"_"+current_scope] << " " << functionName << "(" ;
        
		// You can retrieve and visit the parameter type list
		for (int i=0; i < ctx->AUTO().size()-1; i++) {
			cout << symbol_table[ctx->name()->getText() + to_string(i)+"_"+current_scope];
			if(i != ctx->AUTO().size()-2)
				cout << " , ";		
		}
		cout << ");" << endl;
        return nullptr;
    }

    any visitBlockstmt(BParser::BlockstmtContext *ctx) override {
    	// Perform some actions when visiting a block statement
		cout << "{" << endl;
    	for (auto stmt : ctx->statement()) {
      	    visit(stmt);
    	}
		cout << "}" << endl;
    	return nullptr;
    }

    any visitIfstmt(BParser::IfstmtContext *ctx) override {
		cout << "if (";
		visit(ctx->expr());
		cout << ") " ;

		visit(ctx->statement(0));
		if (ctx->ELSE()) {
	   		cout << endl << "else ";
	   		visit(ctx->statement(1));
		}
        return nullptr;
    }

    any visitWhilestmt(BParser::WhilestmtContext *ctx) override {
        cout << "while (";
        visit(ctx->expr());
        cout << ") ";
        visit(ctx->statement());
        return nullptr;
    }

    any visitExpressionstmt(BParser::ExpressionstmtContext *ctx) override {
		visit(ctx->expression());
		cout << ";" << endl;
        return nullptr;
    }

    any visitReturnstmt(BParser::ReturnstmtContext *ctx) override {
		cout << "return";
		if (ctx->expression()) {
			cout << " (";
			visit(ctx->expression());
			cout << ")";
		}
		cout << ";" << endl;
        return nullptr;
    }

    any visitNullstmt(BParser::NullstmtContext *ctx) override {
		cout << ";" << endl;
        return nullptr;
    }

    any visitExpr(BParser::ExprContext *ctx) override {
		// unary operator
        if(ctx->atom()) {
            if (ctx->PLUS()) cout << "+";
            else if (ctx->MINUS()) cout << "-";
	    	else if (ctx->NOT()) cout << "!";
	    	visit(ctx->atom()); 
        }
		// binary operator
		else if (ctx->MUL() || ctx->DIV() || ctx->PLUS() || ctx->MINUS() || 
		 		ctx->GT() || ctx->GTE() || ctx->LT() || ctx->LTE() || ctx->EQ() || ctx->NEQ() ||
		 		ctx->AND() || ctx->OR() ) {
	    	visit(ctx->expr(0));
	    	cout << " " << ctx->children[1]->getText() << " "; // print binary operator
	    	visit(ctx->expr(1));
		}
		// ternary operator
		else if (ctx->QUEST()) {
			visit(ctx->expr(0));
			cout << " ? ";
			visit(ctx->expr(1));
			cout << " : ";
			visit(ctx->expr(2));
		}
		else {
			int lineNum = ctx->getStart()->getLine();
			cerr << endl << "[ERROR] visitExpr: unrecognized ops in Line " << lineNum << " --" << ctx->children[1]->getText() << endl;
			exit(-1); // error
        }	
        return nullptr;
    }
   
    any visitAtom(BParser::AtomContext *ctx) override {
		if (ctx->expression()) { // ( expression )
			cout << "(";
			visit(ctx->expression());
			cout << ")";
		}
		else	// name | constant | funcinvocation
			visit(ctx->children[0]);
        return nullptr;
    }
    
    any visitExpression(BParser::ExpressionContext *ctx) override {
        if (ctx->ASSN()) { // assignment
	   		visit(ctx->name());
	  		 cout << " = ";
		}
		visit(ctx->expr());
        return nullptr;
    }

    any visitFuncinvocation(BParser::FuncinvocationContext *ctx) override {
		cout << ctx->name()->getText() << "(";
		for (int i=0; i < ctx->expr().size(); i++) {
			if (i != 0) cout << ", ";
			visit(ctx->expr(i));
		}
		cout << ")";
        return nullptr;
    }
    
    any visitConstant(BParser::ConstantContext *ctx) override {
        cout << ctx->children[0]->getText();
        return nullptr;
    }
    
    any visitName(BParser::NameContext *ctx) override {
		cout << ctx->NAME()->getText();
        return nullptr;
    }
    
    any visitDirective(BParser::DirectiveContext *ctx) override {
		cout << ctx->SHARP_DIRECTIVE()->getText();
		cout << endl;
        return nullptr;
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

    cout << "/*-- B2C ANTLR visitor --*/\n";

    ANTLRInputStream inputStream(stream);
    BLexer lexer(&inputStream);
    CommonTokenStream tokenStream(&lexer);
    BParser parser(&tokenStream);
    ParseTree* tree = parser.program();

    // STEP 1. visit parse tree and perform type inference for expressions, function calls
    TypeAnalysisVisitor AnalyzeTree;
    AnalyzeTree.visit(tree);

    // STEP 2. visit parse tree and augment types for 'auto' typed variables --- you may skip this by keeping the class empty 
   // TypeAugmentationVisitor AugmentTree;
   // AugmentTree.visit(tree);

    // STEP 3. visit parse tree and print out C code with augmented types
    PrintTreeVisitor PrintTree;
    PrintTree.visit(tree);

    return 0;
}


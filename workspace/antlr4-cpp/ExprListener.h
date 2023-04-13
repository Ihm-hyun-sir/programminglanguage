
// Generated from Expr.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ExprParser.
 */
class  ExprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(ExprParser::ProgContext *ctx) = 0;
  virtual void exitProg(ExprParser::ProgContext *ctx) = 0;

  virtual void enterExpr(ExprParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ExprParser::ExprContext *ctx) = 0;

  virtual void enterMulexpr(ExprParser::MulexprContext *ctx) = 0;
  virtual void exitMulexpr(ExprParser::MulexprContext *ctx) = 0;

  virtual void enterBarexpr(ExprParser::BarexprContext *ctx) = 0;
  virtual void exitBarexpr(ExprParser::BarexprContext *ctx) = 0;

  virtual void enterOp(ExprParser::OpContext *ctx) = 0;
  virtual void exitOp(ExprParser::OpContext *ctx) = 0;

  virtual void enterAssn(ExprParser::AssnContext *ctx) = 0;
  virtual void exitAssn(ExprParser::AssnContext *ctx) = 0;

  virtual void enterNum(ExprParser::NumContext *ctx) = 0;
  virtual void exitNum(ExprParser::NumContext *ctx) = 0;


};


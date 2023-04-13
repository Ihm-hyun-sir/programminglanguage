
// Generated from Expr.g4 by ANTLR 4.11.1


#include "ExprListener.h"

#include "ExprParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ExprParserStaticData final {
  ExprParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ExprParserStaticData(const ExprParserStaticData&) = delete;
  ExprParserStaticData(ExprParserStaticData&&) = delete;
  ExprParserStaticData& operator=(const ExprParserStaticData&) = delete;
  ExprParserStaticData& operator=(ExprParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag exprParserOnceFlag;
ExprParserStaticData *exprParserStaticData = nullptr;

void exprParserInitialize() {
  assert(exprParserStaticData == nullptr);
  auto staticData = std::make_unique<ExprParserStaticData>(
    std::vector<std::string>{
      "prog", "expr", "mulexpr", "barexpr", "op", "assn", "num"
    },
    std::vector<std::string>{
      "", "", "';'", "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "NEWLINE", "SEMI", "EQUAL", "PLUS", "MINUS", "MUL", "DIV", "LBAR", 
      "RBAR", "INT", "REAL", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,70,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,3,0,18,8,0,1,0,1,0,1,0,3,0,23,8,0,5,0,25,8,0,10,0,12,0,28,9,0,
  	1,1,1,1,1,1,5,1,33,8,1,10,1,12,1,36,9,1,1,2,1,2,1,2,5,2,41,8,2,10,2,12,
  	2,44,9,2,1,3,3,3,47,8,3,1,3,1,3,1,3,1,3,1,3,3,3,54,8,3,1,3,3,3,57,8,3,
  	1,4,1,4,1,5,1,5,1,5,3,5,64,8,5,1,5,1,5,1,6,1,6,1,6,0,0,7,0,2,4,6,8,10,
  	12,0,3,1,0,4,5,1,0,6,7,1,0,10,12,72,0,26,1,0,0,0,2,29,1,0,0,0,4,37,1,
  	0,0,0,6,56,1,0,0,0,8,58,1,0,0,0,10,60,1,0,0,0,12,67,1,0,0,0,14,15,3,10,
  	5,0,15,17,5,2,0,0,16,18,5,1,0,0,17,16,1,0,0,0,17,18,1,0,0,0,18,25,1,0,
  	0,0,19,20,3,2,1,0,20,22,5,2,0,0,21,23,5,1,0,0,22,21,1,0,0,0,22,23,1,0,
  	0,0,23,25,1,0,0,0,24,14,1,0,0,0,24,19,1,0,0,0,25,28,1,0,0,0,26,24,1,0,
  	0,0,26,27,1,0,0,0,27,1,1,0,0,0,28,26,1,0,0,0,29,34,3,4,2,0,30,31,7,0,
  	0,0,31,33,3,4,2,0,32,30,1,0,0,0,33,36,1,0,0,0,34,32,1,0,0,0,34,35,1,0,
  	0,0,35,3,1,0,0,0,36,34,1,0,0,0,37,42,3,6,3,0,38,39,7,1,0,0,39,41,3,6,
  	3,0,40,38,1,0,0,0,41,44,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,5,1,0,
  	0,0,44,42,1,0,0,0,45,47,3,8,4,0,46,45,1,0,0,0,46,47,1,0,0,0,47,48,1,0,
  	0,0,48,49,5,8,0,0,49,50,3,2,1,0,50,51,5,9,0,0,51,57,1,0,0,0,52,54,3,8,
  	4,0,53,52,1,0,0,0,53,54,1,0,0,0,54,55,1,0,0,0,55,57,3,12,6,0,56,46,1,
  	0,0,0,56,53,1,0,0,0,57,7,1,0,0,0,58,59,7,0,0,0,59,9,1,0,0,0,60,61,5,12,
  	0,0,61,63,5,3,0,0,62,64,3,8,4,0,63,62,1,0,0,0,63,64,1,0,0,0,64,65,1,0,
  	0,0,65,66,3,12,6,0,66,11,1,0,0,0,67,68,7,2,0,0,68,13,1,0,0,0,10,17,22,
  	24,26,34,42,46,53,56,63
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  exprParserStaticData = staticData.release();
}

}

ExprParser::ExprParser(TokenStream *input) : ExprParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ExprParser::ExprParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ExprParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *exprParserStaticData->atn, exprParserStaticData->decisionToDFA, exprParserStaticData->sharedContextCache, options);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

const atn::ATN& ExprParser::getATN() const {
  return *exprParserStaticData->atn;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return exprParserStaticData->ruleNames;
}

const dfa::Vocabulary& ExprParser::getVocabulary() const {
  return exprParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ExprParser::getSerializedATN() const {
  return exprParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::AssnContext *> ExprParser::ProgContext::assn() {
  return getRuleContexts<ExprParser::AssnContext>();
}

ExprParser::AssnContext* ExprParser::ProgContext::assn(size_t i) {
  return getRuleContext<ExprParser::AssnContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ProgContext::SEMI() {
  return getTokens(ExprParser::SEMI);
}

tree::TerminalNode* ExprParser::ProgContext::SEMI(size_t i) {
  return getToken(ExprParser::SEMI, i);
}

std::vector<ExprParser::ExprContext *> ExprParser::ProgContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ProgContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ProgContext::NEWLINE() {
  return getTokens(ExprParser::NEWLINE);
}

tree::TerminalNode* ExprParser::ProgContext::NEWLINE(size_t i) {
  return getToken(ExprParser::NEWLINE, i);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}

void ExprParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void ExprParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7472) != 0) {
      setState(24);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(14);
        assn();
        setState(15);
        match(ExprParser::SEMI);
        setState(17);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ExprParser::NEWLINE) {
          setState(16);
          match(ExprParser::NEWLINE);
        }
        break;
      }

      case 2: {
        setState(19);
        expr();
        setState(20);
        match(ExprParser::SEMI);
        setState(22);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ExprParser::NEWLINE) {
          setState(21);
          match(ExprParser::NEWLINE);
        }
        break;
      }

      default:
        break;
      }
      setState(28);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::MulexprContext *> ExprParser::ExprContext::mulexpr() {
  return getRuleContexts<ExprParser::MulexprContext>();
}

ExprParser::MulexprContext* ExprParser::ExprContext::mulexpr(size_t i) {
  return getRuleContext<ExprParser::MulexprContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::ExprContext::PLUS() {
  return getTokens(ExprParser::PLUS);
}

tree::TerminalNode* ExprParser::ExprContext::PLUS(size_t i) {
  return getToken(ExprParser::PLUS, i);
}

std::vector<tree::TerminalNode *> ExprParser::ExprContext::MINUS() {
  return getTokens(ExprParser::MINUS);
}

tree::TerminalNode* ExprParser::ExprContext::MINUS(size_t i) {
  return getToken(ExprParser::MINUS, i);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void ExprParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}

ExprParser::ExprContext* ExprParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    mulexpr();
    setState(34);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::PLUS

    || _la == ExprParser::MINUS) {
      setState(30);
      _la = _input->LA(1);
      if (!(_la == ExprParser::PLUS

      || _la == ExprParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(31);
      mulexpr();
      setState(36);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulexprContext ------------------------------------------------------------------

ExprParser::MulexprContext::MulexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::BarexprContext *> ExprParser::MulexprContext::barexpr() {
  return getRuleContexts<ExprParser::BarexprContext>();
}

ExprParser::BarexprContext* ExprParser::MulexprContext::barexpr(size_t i) {
  return getRuleContext<ExprParser::BarexprContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::MulexprContext::MUL() {
  return getTokens(ExprParser::MUL);
}

tree::TerminalNode* ExprParser::MulexprContext::MUL(size_t i) {
  return getToken(ExprParser::MUL, i);
}

std::vector<tree::TerminalNode *> ExprParser::MulexprContext::DIV() {
  return getTokens(ExprParser::DIV);
}

tree::TerminalNode* ExprParser::MulexprContext::DIV(size_t i) {
  return getToken(ExprParser::DIV, i);
}


size_t ExprParser::MulexprContext::getRuleIndex() const {
  return ExprParser::RuleMulexpr;
}

void ExprParser::MulexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulexpr(this);
}

void ExprParser::MulexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulexpr(this);
}

ExprParser::MulexprContext* ExprParser::mulexpr() {
  MulexprContext *_localctx = _tracker.createInstance<MulexprContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleMulexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    barexpr();
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::MUL

    || _la == ExprParser::DIV) {
      setState(38);
      _la = _input->LA(1);
      if (!(_la == ExprParser::MUL

      || _la == ExprParser::DIV)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(39);
      barexpr();
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BarexprContext ------------------------------------------------------------------

ExprParser::BarexprContext::BarexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::BarexprContext::LBAR() {
  return getToken(ExprParser::LBAR, 0);
}

ExprParser::ExprContext* ExprParser::BarexprContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

tree::TerminalNode* ExprParser::BarexprContext::RBAR() {
  return getToken(ExprParser::RBAR, 0);
}

ExprParser::OpContext* ExprParser::BarexprContext::op() {
  return getRuleContext<ExprParser::OpContext>(0);
}

ExprParser::NumContext* ExprParser::BarexprContext::num() {
  return getRuleContext<ExprParser::NumContext>(0);
}


size_t ExprParser::BarexprContext::getRuleIndex() const {
  return ExprParser::RuleBarexpr;
}

void ExprParser::BarexprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBarexpr(this);
}

void ExprParser::BarexprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBarexpr(this);
}

ExprParser::BarexprContext* ExprParser::barexpr() {
  BarexprContext *_localctx = _tracker.createInstance<BarexprContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleBarexpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(46);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ExprParser::PLUS

      || _la == ExprParser::MINUS) {
        setState(45);
        op();
      }
      setState(48);
      match(ExprParser::LBAR);
      setState(49);
      expr();
      setState(50);
      match(ExprParser::RBAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(53);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ExprParser::PLUS

      || _la == ExprParser::MINUS) {
        setState(52);
        op();
      }
      setState(55);
      num();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpContext ------------------------------------------------------------------

ExprParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::OpContext::PLUS() {
  return getToken(ExprParser::PLUS, 0);
}

tree::TerminalNode* ExprParser::OpContext::MINUS() {
  return getToken(ExprParser::MINUS, 0);
}


size_t ExprParser::OpContext::getRuleIndex() const {
  return ExprParser::RuleOp;
}

void ExprParser::OpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp(this);
}

void ExprParser::OpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp(this);
}

ExprParser::OpContext* ExprParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    _la = _input->LA(1);
    if (!(_la == ExprParser::PLUS

    || _la == ExprParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssnContext ------------------------------------------------------------------

ExprParser::AssnContext::AssnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::AssnContext::ID() {
  return getToken(ExprParser::ID, 0);
}

tree::TerminalNode* ExprParser::AssnContext::EQUAL() {
  return getToken(ExprParser::EQUAL, 0);
}

ExprParser::NumContext* ExprParser::AssnContext::num() {
  return getRuleContext<ExprParser::NumContext>(0);
}

ExprParser::OpContext* ExprParser::AssnContext::op() {
  return getRuleContext<ExprParser::OpContext>(0);
}


size_t ExprParser::AssnContext::getRuleIndex() const {
  return ExprParser::RuleAssn;
}

void ExprParser::AssnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssn(this);
}

void ExprParser::AssnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssn(this);
}

ExprParser::AssnContext* ExprParser::assn() {
  AssnContext *_localctx = _tracker.createInstance<AssnContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleAssn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(ExprParser::ID);
    setState(61);
    match(ExprParser::EQUAL);
    setState(63);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::PLUS

    || _la == ExprParser::MINUS) {
      setState(62);
      op();
    }
    setState(65);
    num();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

ExprParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::NumContext::INT() {
  return getToken(ExprParser::INT, 0);
}

tree::TerminalNode* ExprParser::NumContext::REAL() {
  return getToken(ExprParser::REAL, 0);
}

tree::TerminalNode* ExprParser::NumContext::ID() {
  return getToken(ExprParser::ID, 0);
}


size_t ExprParser::NumContext::getRuleIndex() const {
  return ExprParser::RuleNum;
}

void ExprParser::NumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNum(this);
}

void ExprParser::NumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNum(this);
}

ExprParser::NumContext* ExprParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleNum);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7168) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void ExprParser::initialize() {
  ::antlr4::internal::call_once(exprParserOnceFlag, exprParserInitialize);
}

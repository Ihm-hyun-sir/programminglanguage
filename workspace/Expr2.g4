/* Expr.g4 */
grammar Expr;

// parser rules
prog    :       (assn SEMI NEWLINE? | expr NEWLINE? )*
        ;
expr    :       mulexpr ((PLUS|MINUS) mulexpr)*
        ;
mulexpr :       barexpr ((MUL|DIV) barexpr)*
        ;
barexpr :       op?LBAR expr RBAR
        |       op?num
        |       op?ID
        ;
op      :       PLUS
        |       MINUS
        ;
assn    :        ID EQUAL num
        ;
num     :       INT
        |       REAL
        ;
// lexer rules
NEWLINE :       [\n\r] ;
SEMI	:	';';
EQUAL	:	'=';
PLUS    :       '+';
MINUS   :       '-';
MUL     :       '*';
DIV     :       '/';
LBAR    :       '(';
RBAR    :       ')';
INT     :       [0-9]+ ;
REAL    :       [0-9]+'.'[0-9]* ;
ID      :       [a-zA-Z]+ ;
WS      :       [ \t\r\n]+ -> skip ;

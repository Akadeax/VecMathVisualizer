parser grammar VecMathParser;
/** @header{package dae.gd;} */

options{tokenVocab=VecMathLexer;}

expression : (assign | command) EOF;

assign : (ID ASSIGN)? value SEMI?;

complex: LBRACKET x=value COMMA LPAREN y=value RPAREN RBRACKET;
quaternion: LBRACKET w=value COMMA LPAREN x=value COMMA y=value COMMA z=value RPAREN RBRACKET;
vector : LBRACKET value (COMMA value)* RBRACKET;
literal: FLOAT|complex|vector|quaternion;
value: 
 op=ABS value ABS
 | op=(ADD|MINUS) op2=value
 | op1=value op=POWER op2=value
 | op1=value op=(MUL | DIV | DOT) op2=value  
 | op1=value op=(ADD | MINUS | CROSS) op2=value
 | (f=function)? LPAREN op1=value RPAREN
 | literal
 | ID;

function: SIN|COS|TAN|ASIN|ACOS|ATAN|RADTODEG|DEGTORAD|CON|SQRT|ID;
command : print | PRINTALL | display | CLEARDISPLAY | EXIT | JOKE | clear | precision | HELP;
print: PRINT ID;
display: DISPLAY ID;
precision: PRECISION FLOAT;
clear: CLEAR ID?;
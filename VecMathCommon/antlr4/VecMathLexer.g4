lexer grammar VecMathLexer;
/** @header{package dae.gd;} */
channels{
    whitespace
}

WHITESPACE: [ \t]+ -> channel(whitespace);

ASSIGN: '=' ;
LBRACKET: '[' ;
RBRACKET: ']' ;
LPAREN: '(';
RPAREN: ')';
COMMA: ',' ; 
SEMI: ';' ;

ADD: '+';
MINUS: '-';
MUL: '*';
DIV: '/';
DOT: '.';
ABS: '|';
POWER: '^';
CROSS: '#';

COS: 'cos';
SIN: 'sin';
TAN: 'tan';
ACOS: 'acos';
ASIN: 'asin';
ATAN: 'atan';
DEGTORAD: 'deg2rad';
RADTODEG: 'rad2deg';
CON : 'con';
SQRT: 'sqrt';

PRINT: 'print';
PRECISION: 'precision';
PRINTALL: 'printAll';
DISPLAY: 'display';
CLEARDISPLAY: 'clearDisplay';
EXIT: 'bye' | 'exit';
CLEAR: 'clear';
JOKE: 'joke';
HELP: 'help' | '?';
 
ID : [a-zA-Z]+ [a-zA-Z0-9]* ;
FLOAT: [0-9]+ ('.' [0-9]*)? | '.' [0-9]+;

#include <iostream>
#include <string>
//#include "string.h"
using namespace std;
//#include<sstream>
//#include <fstream>
string token= "batoot";
void match( string );
void error(void);
void program( void );
void stmt_sequence( void);
void statement(void);
void if_stmt(void);
void repeat_stmt(void);
void assign_stmt(void);
void read_stmt(void);
void write_stmt(void);
void exp(void);
void comparison_op(void);
void simple_exp(void);
void addop(void);
void term(void);
void mulop(void);
void factor(void);
void TOKEN(void);





void match(string expectedToken) {if (token == expectedToken)  TOKEN(); //advance; 
else {cout<< "error in expected token: " << expectedToken << "\n"<< "token"<< token<< "here"<<"\n"; exit(0);} //error();
}
void error(){ cout<< "error"; exit(0);}
void program(){ stmt_sequence(); cout<< "Program found"<<"\n";}
void stmt_sequence(){ statement(); while(token== ";"){ match(";"); statement();} cout<< "Statement_Sequence found"<<"\n";}
void statement(){ if (token== "if"){ if_stmt(); cout<< "Statement found"<<"\n";} 
				  else if (token== "repeat"){ repeat_stmt(); cout<< "Statement found"<<"\n";}
				  else if (token== "identifier"){ assign_stmt(); cout<< "Statement found"<<"\n";}
				  else if (token== "read"){ read_stmt(); cout<< "Statement found"<<"\n";}
				  else if (token== "write"){ write_stmt(); cout<< "Statement found"<<"\n";}
				  //else error();
}      
void if_stmt(){match("if"); exp(); match("then");  stmt_sequence(); 
				if (token== "else"){match("else"); stmt_sequence();}
				match("end"); cout<< "IF_Statement found"<<"\n";}
void repeat_stmt(){match("repeat"); stmt_sequence(); match("until"); exp(); cout<< "Repeat_Statement found"<<"\n";}
void assign_stmt(){ match("identifier"); match(":="); exp(); cout<< "Assignment_Statement found"<<"\n";}
void read_stmt(){ match("read");match("identifier"); cout<< "Read_statement found"<<"\n";}
void write_stmt(){match("write"); exp(); cout<< "Write_statement found"<<"\n";}
void exp(){simple_exp(); if (token== "<"|| token== "="){ comparison_op(); simple_exp(); } cout<< "Expression found"<<"\n";}
void comparison_op(){ if (token== "<"){ match("<");} 
				  else if (token== "="){ match("=");} 
				  //else error();
 cout<< "Comparison_Operator found"<<"\n";}
void simple_exp(){ term(); while(token== "+"||token== "-" ){ addop(); term(); } cout<< "Simple_Expression found"<<"\n";}
void addop(){ if (token== "+") match ("+"); else if (token== "-") match ("-"); 
//else error();
 cout<< "Add_Operator found"<<"\n";}
void term(){ factor(); while(token== "*"||token== "/" ){  mulop(); factor(); } cout<< "Term found"<<"\n";}
void mulop(){if (token== "*") match ("*"); else if (token== "/") match ("/");
 //else error();
 cout<< "Mul_Operator found"<<"\n";}
 void factor(){if (token== "("){ match("("); exp(); match(")");} else if (token== "number") match("number"); else if (token== "identifier") match("identifier"); 
//else error();
 cout<< "Factor found"<<"\n";}



 void TOKEN(){
//this function updates token
	 token="";
string LeftPart;
string ColonPart;
string RightPart;
cin>>LeftPart;
cin>>ColonPart;
cin>>RightPart;
if ( RightPart == "special" || RightPart == "reserved" ) {string h ; cin>> h; RightPart= RightPart+ " "+ h ; }
if (RightPart == "identifier" || RightPart == "number") token = RightPart;
if ( RightPart == "special symbol" || RightPart == "reserved word" )token = LeftPart;
//cout<< "\n"<<" TOKEN FUNCTION Left " << LeftPart <<"\n"<<"Colon "<<ColonPart<<"\n"<< "Right "<<RightPart<<"Token is"<< token;
//*************************************a3del el scanner to be something space colon space something enter 
//part is rightpart and left part and colon
//fe 7alet id or number token is right part 
//special symbol or reserved character token is left part
}




void main (){
	//string token;
	freopen("scanner_output.txt","r",stdin);
	freopen("parser_output.txt","w",stdout);
	TOKEN(); //updates the token value
	program();}
	//cout<<"kkkkkkkkkkkkkk";}
	//system( "PAUSE" );
	//return 0;}
	//ifstream in("scanner_output.txt");
	//stringstream buffer;
	//buffer << in.rdbuf();
	//string contents(buffer.str()); //a string of all file contents
	//ofstream outfile;
	//outfile.open("parser_output.txt"); //open output file
	//outfile<< word <<": special symbol"<<"\n";
	//outfile.close();
	

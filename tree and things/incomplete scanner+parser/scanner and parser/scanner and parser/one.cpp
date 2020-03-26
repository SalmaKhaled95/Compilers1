//create gloabal dynamic array of strings
//write everything in global array so update write in scanner
//read from array and update the index after each read so update read in parser
//change the write of parser



//beginning

#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
using namespace std;
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
void parser (void)
void scanner (void)

//functions

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






//scanner



void scanner (){
	string flag= "start"; //states
	string word=""; // a string that has the full number of the full letters of an id or reserved word
	int dody=9; //used for an input file that has only : in it and needs an output
	string x;
	string letter; // a string of one letter
	//input file
	ifstream in("tiny_sample_code.txt");

	stringstream buffer;
	buffer << in.rdbuf();

string contents(buffer.str()); //a string of all file contents
ofstream outfile;
outfile.open("scanner_output.txt"); //open output file
string LETTER;
while (contents!=""){
letter= contents.substr(0,1);
contents= contents.substr(1);
label:
if (flag == "start"){
	if (letter == " "){
	flag = "start";
		}
	 else if (letter == "{"){
		//outfile<< "{: special symbol"<<"\n";
		flag = "comment";
	}
	else if (letter == "a"|| letter == "b"|| letter == "c"||letter == "d"||letter == "e"||letter == "f"||letter == "g"||
		letter == "h"||letter == "i"||letter == "j"||letter == "k"||letter == "l"||letter == "m"||letter == "n"||letter == "o"||
		letter == "p"||letter == "q"||letter == "r"||letter == "s"||letter == "t"||letter == "u"||letter == "v"||letter == "w"||
		letter == "x"||letter == "y"||letter == "z"||letter == "A"||letter == "B"||letter == "C"||letter == "D"||letter == "E"||
		letter == "F"||letter == "G"||letter == "H"||letter == "I"||letter == "J"||letter == "K"||letter == "L"||letter == "M"||
		letter == "N"||letter == "O"||letter == "P"||letter == "Q"||letter == "R"||letter == "S"||letter == "T"||letter == "U"||
		letter == "V"||letter == "W"||letter == "X"||letter == "Y"||letter == "Z"){
	flag= "identifier";
	word+= letter;
	}
	else if (letter == "0"|| letter == "1"||letter == "2"||letter == "3"||letter == "4"||letter == "5"||letter == "6"||
		letter == "7"||letter == "8"||letter == "9"){
	flag= "number";
	word+= letter;
	}
	else if (letter == ":"){
	flag= "assignment";
	word+= letter;
	dody=1;
	}
	else {
		if (letter=="+"|| letter=="-"||letter=="*"||letter=="/"||letter=="="||letter=="<"||letter=="("||
			letter==")"||letter==";")
		{outfile<< letter <<": special symbol"<<"\n";}
		flag ="start"; //done
			}
}
else if (flag == "comment"){
	if (letter=="}"){
		//outfile<< "}: special symbol"<<"\n";
		flag = "start";
	}
	else {flag = "comment";}
}
else if (flag == "number"){
	if (letter == "0"|| letter == "1"||letter == "2"||letter == "3"||letter == "4"||letter == "5"||letter == "6"||
		letter == "7"||letter == "8"||letter == "9"){
	flag= "number";
	word+= letter;
	}
	else{
	flag= "start"; //done
	outfile<< word <<": number"<<"\n";
	word="";
	goto label;
	}
}
else if (flag == "identifier"){
	if (letter == "a"|| letter == "b"|| letter == "c"||letter == "d"||letter == "e"||letter == "f"||letter == "g"||
		letter == "h"||letter == "i"||letter == "j"||letter == "k"||letter == "l"||letter == "m"||letter == "n"||letter == "o"||
		letter == "p"||letter == "q"||letter == "r"||letter == "s"||letter == "t"||letter == "u"||letter == "v"||letter == "w"||
		letter == "x"||letter == "y"||letter == "z"||letter == "A"||letter == "B"||letter == "C"||letter == "D"||letter == "E"||
		letter == "F"||letter == "G"||letter == "H"||letter == "I"||letter == "J"||letter == "K"||letter == "L"||letter == "M"||
		letter == "N"||letter == "O"||letter == "P"||letter == "Q"||letter == "R"||letter == "S"||letter == "T"||letter == "U"||
		letter == "V"||letter == "W"||letter == "X"||letter == "Y"||letter == "Z"){
	flag= "identifier";
	word+= letter;
	}
	else{
	flag= "start"; //done
	if (word== "if" || word== "then" || word== "else" || word== "end" || word== "repeat"|| 
		word== "until"|| word== "read"|| word== "write"){outfile<< word <<": reserved word"<<"\n";}
	else {outfile<< word <<": identifier"<<"\n";}
	word="";
	goto label;}}
else if (flag == "assignment"){
if (letter=="="){
	word+=letter;
	outfile<< word <<": special symbol"<<"\n";
	word="";
		flag = "start";
		dody=0;
		//done
	} 
	else {flag = "start";
	outfile<< word <<": special symbol"<<"\n";
	dody=0;
	word="";
		goto label;
		//done
	} 
}
//else if (flag == "done"){cout<<"";}
}
if (dody==1) outfile<< word <<": identifier"<<"\n";
//close output file
outfile.close();
system( "PAUSE" );
}






//////////////////////////////////////////////
//parser

void parser (){
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
	




////main function

void main(){
scanner();
parser();

}
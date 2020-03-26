#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
using namespace std;
int main (){
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
return 0;
}

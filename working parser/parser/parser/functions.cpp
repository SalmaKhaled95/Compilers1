void match(string expectedToken) {if (token == expectedToken)  TOKEN(); //advance; 
								  else error();}
void error(){ cout<< "error"; exit(0);}
void program(){ stmt-sequence(); cout<< "Program found"<<"\n";}
void stmt-sequence(){ statement(); match("{"); match(";"); statement(); match("}"); cout<< "Statement Sequence found"<<"\n";}
void statement(){ if (token== "if"){ if-stmt();} 
				  else if (token== "repeat"){ repeat-stmt();}
				  else if (token== "identifier"){ assign-stmt();}
				  else if (token== "read"){ read-stmt();}
				  else if (token== "write"){ write-stmt();}
				  else error();}      
void if-stmt(){match("if"); exp(); match("then");  stmt-sequence(); 
				if (token== "else"){match("else"); stmt-sequence();}
				match("end"); cout<< "If statement found"<<"\n";}
void repeat-stmt(){match("repeat"); stmt-sequence(); match("until"); exp(); cout<< "Repeat statement found"<<"\n";}}
void assign-stmt(){ match("identifier"); match(":="); exp(); cout<< "Assignment found"<<"\n";}}
void read-stmt(){ match("read");match("identifier"); cout<< "Read statement found"<<"\n";}}
void write-stmt(){match("write"); exp(); cout<< "Write statement found"<<"\n";}}
void exp(){simple-exp(); match("["); comparison-op(); simple-exp(); match("]"); cout<< "Expression found"<<"\n";}}
void comparison-op(){ if (token== '<'){ match('<');} 
				  else if (token== "="){ match('=');} 
				  else error(); cout<< "Comparison found"<<"\n";}}
void simple-exp(){ term(); match("{"); addop(); term(); match("}"); cout<< "Simple Expression found"<<"\n";}}
void addop(){ if (token== '+') match ('+'); else if (token== '-') match ('-'); else error(); cout<< "Operand found"<<"\n";}}
void term(){ factor(); match("{"); mulop(); factor(); match("}"); cout<< "term found"<<"\n";}
void mulop(){if (token== '*') match ('*'); else if (token== '/') match ('/'); else error(); cout<< "Operand found"<<"\n";}
 void factor(){if (token== '('){ match("("); exp(); match(")");} else if (token== "number") match("number"); else if (token== "identifier") match("identifier"); else error(); cout<< "factor found"<<"\n";}



 void TOKEN(){
//this function updates token
string LeftPart;
string ColonPart;
string RightPart;
cin>>LeftPart;
cin>>ColonPart;
cin>>RightPart;
if ( RightPart == "special" || RightPart == "reserved" ) {string h ; cin>> h; RightPart= RightPart+ " "+ h ; }
if (RightPart == "identifier" || RightPart == "number") token = RightPart;
if ( LeftPart == "special symbol" || LeftPart == "reserved word" )token = LeftPart;

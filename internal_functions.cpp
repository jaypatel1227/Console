
// This contains internal functions to be used in commands.cpp

#include "commands.h"
#include "internal_functions.h"

void evaluate(string inp){
  if (inp == "exit"){
	return;
  }
  if (begins_with(inp, "echo ")){
	echo(inp);
  }
  else if (begins_with(inp, "list_nums ")){
	list_nums(inp);
  }
  else if (begins_with(inp, "cat ")){
	cat(inp);
  }
  else if (begins_with(inp, "touch ")){
	touch(inp);
  }
  else if (begins_with(inp, "head ")){
	head(inp);
  }
  else if (begins_with(inp, "tail ")){
	tail(inp);
  }
  else if (begins_with(inp, "clear")){
	clear();
  }
  else{
	cout << "Unable to read that command." << endl;
  }
}

//////////////////// Internal functions 

bool begins_with(string inp, string match){
  bool flag = true;
  for (int i = 0; i < int(match.length()); i++){
	if (inp[i] != match[i]){
	  flag = false;
	  break;
	}
  }
  return flag;
}

string remove_match_front(string inp, string match){
  string res = "";
  for (int i = int(match.length()); i < int(inp.length()); i++){
	res += inp[i];
  }
  return res;
}

bool ends_with(string inp, string match){
  bool flag = true;
  for (int i = int(match.length()-1); i >= 0; i--){
	if (inp[i] != match[i]){
	  flag = false;
	  break;
	}
  }
  return flag;
}

string remove_match_end(string inp, string match){
  string res = "";
  for (int i = 0; i < int(inp.length() - match.length()); i--){
	res += inp[i];
  }
  return res;
}

int read_num(string inp){
  return stoi(inp.substr(0, inp.find(" ")));
}

string read_word(string inp){
  return inp.substr(0, inp.find(" "));
}

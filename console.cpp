// #include <iostream>
// #include <fstream>
// #include <string>
#include "console.h"

using namespace std;
// using namespace std::experimental::filesystem;

int main() {
  string prompt = "prompt:/> ";
  string inp = "";
  while (inp != "exit"){
	cout << prompt;
	getline(cin, inp);
	if (ends_with(inp, "\\")){
	  string temp = "";
	  while(not ends_with(inp, "\\")){
		cin >> temp;
		inp = inp + "\n" + temp;
	  }
	}
	evaluate(inp);
  }
}

void evaluate(string inp){
  if (inp == "exit"){
	return;
  }
  if (begins_with(inp, "echo")){
	echo(inp);
  }
  else if (begins_with(inp, "list_nums")){
	list_nums(inp);
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
  string num = "";
  for (int i = 0; i < int(inp.length()); i++){
	if (isdigit(inp[i]) == 0){
	  break;
	}
	num += inp[i];
  }
  return stoi(num);
}

//////////////////// Commands

void echo(string inp){
  cout << remove_match_front(inp, "echo ") << endl;
}

void list_nums(string inp){
  string args = remove_match_front(inp, "list_nums ");
  int low = read_num(args);
  args = remove_match_front(args, to_string(low) + " ");
  int high = read_num(args);
  args = remove_match_front(args, to_string(high));
  for (int i = low; i <= high; i++){
	cout << i << endl;
  }
}

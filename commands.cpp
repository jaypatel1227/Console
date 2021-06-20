
// This is a file to store all of the commands used in console.cpp

#include "commands.h"
#include "internal_functions.h"

using namespace std;

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

void cat(string inp){
  inp = remove_match_front(inp, "cat ");
  string file = "";
  while (inp != ""){
	file = read_word(inp);
	inp = remove_match_front(inp, file + " ");
	ifstream File(file);
	string line;
	cout << "---" << file << "---" << endl;
	while (getline(File, line)){
	  cout << line << endl;
	}
	File.close();
	cout << endl;
  }

}

void touch(string inp){
  ofstream my_out(remove_match_front(inp, "touch "));
  my_out << "";
  my_out.close();
}

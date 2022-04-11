use std::io::{stdin, stdout, Write};
use std::process::{Command};


fn main() {
    loop{
        print!("$> ");
        stdout().flush().unwrap();

        let mut inp = String::new();
        
        // now, we read in the input line from the user
        stdin().read_line(&mut inp).unwrap();
        // however, the read_line include the newline character from the user input and so, we want to .trim the input so that the new line is removed
        
        let mut command = Command::new(inp.trim())
            .spawn()
            .unwrap();

        command.wait();
    }
}

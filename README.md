# ccwc – A wc Clone in C

This is my own implementation of the Unix `wc` (word count) tool, written in C.  
It supports counting **lines, words, characters, and bytes** from files or standard input.

---

## Features
- `-c` : Count bytes
- `-l` : Count lines
- `-w` : Count words
- Supports **multiple flags combined** (e.g., `-clw`)
- Works with **standard input** (e.g., `cat file.txt | ./ccwc -w`)
- Error handling with `errno`

## Installing as a Command

1. Compile the program  
   gcc ccwc.c -o ccwc  

2. Install the executable  

   If you have sudo permissions:  
   Move the executable to /usr/local/bin  
   sudo mv ccwc /usr/local/bin/  

   If you do not have sudo permissions:  
   1. Create a bin directory in your home (if it doesn’t exist):  
      mkdir -p ~/bin  
   2. Move the executable into that directory:  
      mv ccwc ~/bin/  
   3. Add ~/bin to your PATH by appending this line to your ~/.bashrc (or ~/.zshrc if you use zsh):  
      echo 'export PATH="$HOME/bin:$PATH"' >> ~/.bashrc  
   4. Reload your shell configuration:  
      source ~/.bashrc  

3. Test the command  
   ccwc -l file.txt  


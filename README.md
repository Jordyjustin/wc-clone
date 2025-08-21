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

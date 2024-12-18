# 📝 SMWC - Simple Word Count Tool  

**SMWC** is a versatile word count tool that provides information about the **words**, **lines**, and **bytes** in a file.  

## Features  
- Count the number of **lines** (`-l`)  
- Count the number of **words** (`-w`)  
- Count the number of **bytes** (`-c`)  
- Without any parameter, it displays all three counts for the given file.  

## Requirements  
Make sure you have a **C++ compiler** installed on your system (e.g., `g++`).  

## Compilation  
Save the C++ file (e.g., `smwc.cpp`) and compile it with the following command:  
```bash
g++ smwc.cpp -o smwc
```
## Usage
After successful compilation, execute the tool as follows:

To view bytes, lines, and words of a file:

```bash
./smwc test.txt
```
To view only byte count:

```bash
./smwc -c test.txt
```
To view only word count:

```bash
./smwc -w test.txt
```
To view only line count:

```bash
./smwc -l test.txt
```
## How to Run Directly from the Terminal
To make SMWC available as a global command, follow these steps:

Compile the program:

```bash
g++ smwc.cpp -o smwc
```
Move the executable to a directory which is in your system's PATH (e.g., /usr/local/bin):

```bash
sudo mv smwc /usr/local/bin
```
Now you can run smwc directly from the terminal:

```bash
smwc test.txt
```
Enjoy using SMWC! 🎉
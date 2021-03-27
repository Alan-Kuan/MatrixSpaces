# Matrix Spaces
This is a tool to help you get four fundamental spaces of a matrix: **column space**, **row space**, **nullspace**, and **left nullspace**.

![screenshot of a testcase's result](https://raw.githubusercontent.com/Alan-Kuan/MatrixSpaces/master/screenshot.png)

## Build
```bash
git clone https://github.com/Alan-Kuan/MatrixSpaces.git
cd MatrixSpaces
make
```

After running above commands, you may see an executable file "run" in the current directory.

## Usage
In any text file:
```
[row size] [column size]
[elements]
```

**Note**: Remember to separate each element with at least one white-space.
Besides, you may provide as many matrices as you like.

Example:
```
2 3
4  5 6
1 -9 4

3 3
1 2 3
4 5 6
7 8 9
```
Then execute "run" with the text file's name as an argument.
```bash
./run [FILE]
```

## License
This tool was published under the MIT License.

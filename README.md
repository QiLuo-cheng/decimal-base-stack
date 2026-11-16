# Decimal to Binary, Octal and Hexadecimal with a Stack

这是数据结构实践任务“十进制转换为二进制、八进制、十六进制”的 C 语言实现。

程序使用顺序栈保存每次除法得到的余数，再利用栈“后进先出”的特点，把余数按相反顺序输出。

## 转换原理

以十进制数 `42` 转二进制为例：

```text
42 / 2 = 21 ... 0   入栈
21 / 2 = 10 ... 1   入栈
10 / 2 =  5 ... 0   入栈
 5 / 2 =  2 ... 1   入栈
 2 / 2 =  1 ... 0   入栈
 1 / 2 =  0 ... 1   入栈

依次出栈：1 0 1 0 1 0
```

八进制和十六进制使用相同方法，只是除数分别改为 `8` 和 `16`。

## 文件说明

- `converter.c`：程序源代码
- `README.md`：任务与运行说明
- `GITHUB_UPLOAD_GUIDE.md`：把本项目上传到 GitHub 的步骤
- `.gitignore`：忽略编译生成的文件

## 编译方法

### Windows（MinGW / GCC）

在项目目录打开 PowerShell：

```powershell
gcc -std=c11 -Wall -Wextra -O2 converter.c -o converter.exe
.\converter.exe
```

### Linux / macOS

```bash
gcc -std=c11 -Wall -Wextra -O2 converter.c -o converter
./converter
```

## 运行示例

```text
Input a decimal integer: 42

Results:
Binary: 101010
Octal: 52
Hexadecimal: 2A
```

负数会保留负号，例如输入 `-42` 时输出 `-101010`、`-52`、`-2A`。输入 `0` 时三种进制都输出 `0`。

## 说明

程序使用 `long long` 读取整数，支持 64 位有符号整数范围。如果题目要求支持超过 64 位的任意大整数，则需要改为字符串存储并实现大整数除法。

### Boolen and Nil
**nil**和**false**都表示假值
**nil**有时表“无”或“未知”，在条件表达式中表示**false**
**true**表示真值，条件表达式中除**nil**和**false**都表示真值
### Number Literals
#### Integer Literals
下划线用于提高数字可读性，可于任意位置添加
可通过不同前缀来表示不同进制的数字(字母不区分大小写)：
1. 十进制：0d
2. 十六进制：0x
3. 八进制：0，0o
4. 二进制：0b
#### Float Literals
下划线同上
使用e/E可以表示科学记数法
#### Rational Literals
使用后缀**r**来书写Rational
```ruby
1r       # => (1/1)
2/3r     # => (2/3)   # With denominator.
-1r      # => (-1/1)  # With signs.
-2/3r    # => (-2/3)
2/-3r    # => (-2/3)
-2/-3r   # => (2/3)
+1/+3r   # => (1/3)
1.2r     # => (6/5)   # With fractional part.
1_1/2_1r # => (11/21) # With embedded underscores.
2/4r     # => (1/2)   # Automatically reduced.
```
由于
```ruby
<digit> = '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
```
所以，使用浮点数会被视为浮点数除有理数分母
```ruby
1.2/3r  # => 0.39999999999999997
```
#### Complex Literals
使用后缀**i**来表示复数
用**ri**表示纯虚数？疑似可以避免精度问题？
```ruby
12.3i
=> (0+12.3i)   #括号内表示实部+虚部
12.3ri
=> (0+(123/10)*i)
```
**i**必须于**r**后
### String
#### Escaoe Sequences
全部转义序列：
```ruby
\a             响铃（bell），ASCII 07h (BEL)        # 发出终端蜂鸣声
\b             退格（backspace），ASCII 08h (BS)      # 光标后退一格
\t             水平制表符（horizontal tab），ASCII 09h (TAB)  # Tab 键
\n             换行符（newline / line feed），ASCII 0Ah (LF)   # 新起一行
\v             垂直制表符（vertical tab），ASCII 0Bh (VT)
\f             换页符（form feed），ASCII 0Ch (FF)    # 打印机换页
\r             回车符（carriage return），ASCII 0Dh (CR)  # 光标回到行首
\e             Escape 字符，ASCII 1Bh (ESC)           # 终端控制序列开头
\s             空格（space），ASCII 20h (SPC)
\\             反斜杠本身，\
\nnn           八进制位模式，其中 nnn 是 1-3 位八进制数字（[0-7]）
\xnn           十六进制位模式，其中 nn 是 1-2 位十六进制数字（[0-9a-fA-F]）
\unnnn         Unicode 字符，其中 nnnn 恰好是 4 位十六进制数字（[0-9a-fA-F]）
\u{nnnn ...}   一个或多个 Unicode 字符，每个 nnnn 是 1-6 位十六进制数字（[0-9a-fA-F]）
\cx 或 \C-x    控制字符（control character），x 是可打印的 ASCII 字符
\M-x           Meta 字符，x 是可打印的 ASCII 字符（最高位设为 1）
\M-\C-x        Meta 控制字符，x 是可打印的 ASCII 字符
\M-\cx         同上
\c\M-x         同上
\c? 或 \C-?    Delete 字符，ASCII 7Fh (DEL)
\<newline>     续行符（continuation line），表示空字符串（即字符串可以跨多行写，换行处不产生字符）
```
#### Double-Quotes String Literals
双引号字符串支持**转义序列**和#{...}
在双引号字符串中使用符号需要用反斜杠
#{}可以被简写为#
#### Single-Quoted String Literals
单引号字符串会禁用插值和转义序列
只用 <u>\'</u> 和 <u>\\</u> 被允许使用
反斜杠后字符会被解释为反斜杠和字符本身
#### Literal Concatenation
解释器会自动连接相邻字符串，使用 <u>\</u> 亦会自动连接
百分号字符串不能是最后一个
#### Character Literal
以 ? 后跟一个字符或转义序列为语法，表示单个字符或转义序列（这是旧版用法）
#### Here Document Literals
 用于编写大段文字
 以 **<< HEREDOC** 开始，到 **HEREDOC** 结束
通过在 **<<** 后添加 **-**  使得结束符可以被缩进（即可以在其前方使用空格、Tab等）
**HEREDOC** 中的内容始终以左对齐形式出现
通过在 **<<** 后添加 **~** 使得内容和结尾都被允许使用缩进
该操作会有以下行为：
1. 找到第一个非空行后，计算最小缩进，所有行减去最小缩进确保左对齐
2. 转义的Tab和空格不算缩进
3. Tab被视为1~8的空格，若要移除的最小缩进数在制表符中间，则不予移除
Heredoc允许使用插值和转义序列，通过将起始符使用 **单引号** 括起使其遭到禁用
使用引号则会使除了引号和换行符外的任何字符被视为标识符
**调用Heredoc上的方法** ，请将其放在标识符后
同时打开多个Heredoc是被允许的，以下为例子：
```ruby
puts(<<-ONE, <<-TWO)
content for heredoc one
ONE
content for heredoc two
TWO
```
#### Symbol Literals
**Symbol**是ruby中解释器内部的一个名称
使用冒号来引用符号字面量
通过插值和转义序列创建一个符号字面量
单引号可以用来禁止插值和转义序列】
#### Array Literals
使用**方括号[]** 来创建一个数组字面量
数组字面量可以包含表达式
```ruby
[1, 1 + 1, 1 + 2]
[1, [1 + 1, [1 + 2]]]
```
#### Hash Literals
使用**大括号{}** 来创建一个哈希字面量
```ruby
{ "a" => 1, "b" => 2 }
```
也可以这么写
```ruby
{ a: 1, b: 2 }
```
如果符号键包含空格、特殊字符，或者想动态计算键名，就需要用引号包起来
可以以如下两种方法写：
```ruby
{ "a 1": 1, "b #{1 + 1}": 2 }
{ :"a 1" => 1, :"b 2" => 2 }
```
这两种写法完全等价
当然，也可以省略哈希值
写法如下：
```ruby
x = 100
y = 200
h = { x:, y: }
#=> {:x=>100, :y=>200}
```
#### Range Literals
范围字面量可以表示一个范围，可以没有起始值和结束值
例子如下：
```ruby
(1..5).to_a     # => [1, 2, 3, 4, 5]      # 包含 5
(1...5).to_a    # => [1, 2, 3, 4]         # 不包含 5

('a'..'e').to_a # => ["a", "b", "c", "d", "e"]  # 字母也行
('a'...'e').to_a# => ["a", "b", "c", "d"]     # 不包含 'e'

(1..).take(10)  # => [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  # 无结束范围，取前10个
(..10).take(10) # => [-10, -9, ..., 0, ..., 10]（从负无穷开始）
```
#### Regexp Literals
使用**斜杠/.../** 包裹来创建一个正则字面量
正则表达式可以结合转义字符使用插值
#### Lambda Proc Literals
使用 **箭头->** 来创建一个 **Lambda** 过程
```ruby
-> { 1 + 1 }
```
也可以使用参数
```ruby
->(v) { 1 + v }
```
这会使参数加一
#### Percent Literals
百分比字面量可以各种字符来进行包裹
包括的**成对分隔符 [] () {} <>**
分隔符可以用反斜杠转义。但是，前四对分隔符（方括号、圆括号、花括号和尖括号）只要配对正确，就允许不使用反斜杠
***%q：Non-Interpolable string Literais***
使用**该方式%q**可以创建一个不可插值的字符串
类似单引号，只有反斜杠和指定的分隔符才可以用反斜杠转义
***% and %Q：Interpolable String Literals***
 这样就可以创建一个可插值的字符串
 类似双引号，它允许使用转义序列中描述的转义序列。其他转义字符（反斜杠后跟一个字符）将被解释为该字符本身。
***%w and %W： String-Array Literals***
**不可插值%w，可插值%W** 来进行创建
该字面量可以将字符串数组写成空格分隔的单词
以下会被视为空格
1. 空格，ASCII 20h（SPC）
2. ，ASCII 0ch（FF）
3. 





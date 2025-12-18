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


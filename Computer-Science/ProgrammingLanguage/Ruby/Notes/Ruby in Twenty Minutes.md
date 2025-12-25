## 定义一个方法
```ruby
#示例
def initialize(names = "World")
    @names = names
  end
def say_hi   
    if @names.nil? 
      puts "..."
    elsif @names.respond_to?("each")
      # @names is a list of some kind, iterate!
      @names.each do |name|
        puts "Hello #{name}!"
      end
    else
      puts "Hello #{@names}!"
    end
    
#调用
say_hi "chris"
say_hi
```
***解释***
**initialize,say_hi** :  方法名
**names** ： 参数
**#{name}** ：是ruby向字符串中插入内容的方式，{}内的内容会转换为字符串，后替换至外面的字符串
**names = "World"**： 表示未提供则使用默认参数World

## 定义一个类
```ruby
#示例
class MegaGreeter
  attr_accessor :names
  # Create the object
  def initialize(names = "World")
    @names = names
  end
  # Say hi to everybody
  def say_hi
    if @names.nil?
      puts "..."
    elsif @names.respond_to?("each")
      # @names is a list of some kind, iterate!
      @names.each do |name|
        puts "Hello #{name}!"
      end
    else
      puts "Hello #{@names}!"
    end
  end
  # Say bye to everybody
  def say_bye
    if @names.nil?
      puts "..."
    elsif @names.respond_to?("join")
      # Join the list elements with commas
      puts "Goodbye #{@names.join(", ")}.  Come back soon!"
    else
      puts "Goodbye #{@names}.  Come back soon!"
    end
  end
end

#调用
greeter = MegaGreeter.new("Pat") #创建对象
greeter.say_hi
greeter.say_bye
#greeter.@name 无法使用，无法直接获取实例变量

#获取Greeter对象的方法
MegaGreeter.instance_methods #包括祖先类定义的方法
MegaGreeter.instance_methods(false) #不包括祖先类定义的方法

#使用attr_accessor来查看并改变对象变量
class Greeter
	attr_accessor :name
end
```
***解释***
**MegaGreeter**：类名
**initialize**：类的构造方法，使用new创建对象时自动调用，常用于初始化对象属性，设置默认值，关键字传递
**@name**：实例变量，可供该类中所有方法使用。
**attr_accessor**：定义了两个新方法，name用于获取值，name=用于设置值

## 循环和迭代
```ruby
@names.each do |name|
  puts "Hello #{name}!"
end
```
***解释***
**each**：each是一个方法，接受并对列表中每个元素执行该代码块


### 剧本开篇？机翻
```ruby
if __FILE__ == $0
```
***解释***
**__FILE__**：魔法变量，存储当前文件名称
**$0**：用于启动程序的文件名
该行代码用于检查“如果这是当前正在使用的主文件”，允许将文件用作库，而不执行其上下文中的代码；但如果文件被用作可执行文件，则执行其代码。
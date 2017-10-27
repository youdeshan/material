http://www.360doc.com/content/17/1027/09/48917496_698495323.shtml

所有 C# 的类型都是从 object 类继承的。有两种数据类型：
1.    基本/内建类型
2.    用户定义类型

值类型：在堆栈中分配的数据类型，包括：
	除字符串外所有基本的内建类型
	结构
	枚举类型

引用类型：在堆(heap)中分配内存且当其不再使用时，将自动进行垃圾清理.
引用类型包括：
    类
    接口
    集合类型如数组
    字符串

修饰符
readonly
readonly 修饰符仅用于修饰类的数据成员.
正如其名字说的，一旦它们已经进行了写操作、直接初始化或在构造函数中对其进行了赋值，
readonly 数据成员就只能对其进行读取。
readonly 和 const 数据成员不同之处在于 const 要求你在声明时进行直接初始化

sealed
带有 sealed 修饰符的类不允许你从它继承任何类。所以如果你不想一个类被继承，你可以对该类使用 sealed 关键字。 

unsafe
你可以使用 unsafe 修饰符在 C# 中定义一个不安全上下文。
在不安全上下文中，你可以插入不安全代码，如 C++ 的指针等
public unsafe MyFunction( int * pInt, double* pDouble)
{
    int* pAnotherInt = new int;
    *pAnotherInt  = 10;
    pInt = pAnotherInt;
    ...
    *pDouble = 8.9;    
} 

C# 中你不能对类进行多重继承
通过接口，多重继承的精髓得以实现。即你的子类可以实现多重接口

C# 支持一维、多维和交错数组（数组的数组）
int[] array = new int[10]; // int 型一维数组 
int[,] array2 = new int[5,10]; // int 型二维数组 
int[,,] array3 = new int[5,10,5]; // int 型三维数组
int[][] arrayOfarray = new int[2]; // int 型交错数组 - 数组的数组
arrayOfarray[0] = new int[4]; 
arrayOfarray[1] = new int[] {1,2,15}; 

索引器 
索引器用于书写一个可以通过使用 [] 像数组一样直接访问集合元素的方法
class Shapes: CollectionBase {  
//indexer
    public Shape this[int index] { 
        get { 
            return (Shape) List[index];
        } 
        set {
            List[index] = value ;
        }
    }
} 

装箱/拆箱
基础的或是原始的类型打包为一个对象称为装箱，相反的处理称为拆箱。
int myInt = 12;
object obj = myInt ;      // 装箱
int myInt2 = (int) obj;  // 拆箱 
当某种值类型的变量需要被转换为一个引用类型时，便会产生一个对象箱保存该值。
拆箱则完全相反。当某个对象箱被转换回其原值类型时，该值从箱中拷贝至适当的存储空间。

函数参数
1. 按值传递/输入参数 
值参数的概念和 C++ 中一样。传递的值复制到了新的地方并传递给函数

2. 按引用传递/输入-输出参数
引用参数也被称为输入-输出参数
不能将未初始化的引用参数传递给函数。C# 使用关键字 ref 指定引用参数。
你同时还必须在传递参数给要求引用参数的函数时使用关键字 ref。
void FunctionA(ref int Val){
    int x= Val; 
    Val = x* 4;    
}  
int a= 5;
FunctionA(ref a); // 使用 ref，否则将引发编译时错误
Console.WriteLine(a); // 打印 20 

3. 输出参数 
输出参数是只从函数返回值的参数。输入值不要求。C# 使用关键字 out 表示输出参数。
bool GetNodeValue(out int Val) {
    Val = value;
    return true; 
} 
int Val;
GetNodeValue(Val); 

参数和数组的数量变化 
C# 中的数组使用关键字 params 进行传递。
一个数组类型的参数必须总是函数最右边的参数。
只有一个参数可以是数组类型。你可以传送任意数量的元素作为数组类型的参数
注意：使用数组是 C# 提供用于可选或可变数量参数的唯一途径
void Func(params int[] array){
    Console.WriteLine("number of elements {0}", array.Length);
}
Func(); // 打印 0
Func(5); // 打印 1
Func(7,9); // 打印 2
Func(new int[] {3,8,10}); // 打印 3
int[] array = new int[8] {1,3,4,5,5,6,7,5};
Func(array); // 打印 8 

运算符与表达式
运算符和表达式跟 C++ 中完全一致。然而同时也添加了一些新的有用的运算符 
1. is 运算符(返回bool值)
is 运算符是用于检查操作数类型是否相等或可以转换。is 运算符特别适合用于多态的情形。
is 运算符使用两个操作数，其结果是布尔值
void function(object param){ 
    if(param is ClassA)
        //做要做的事
    else if(param is MyStruct)
        //做要做的事        
    }
} 

2. as 运算符 (返回对象或者null)
as 运算符检查操作数的类型是否可转换或是相等（as 是由 is 运算符完成的），
如果是，则处理结果是已转换或已装箱的对象（如果操作数可以装箱为目标类型，参考 装箱/拆箱）。
如果对象不是可转换的或可装箱的，返回值为 null

foreach 
lock -- 将语句块标记为临界区
checked/unchecked -- 用于数字操作中的溢出检查

Switch
1.现在在执行一条 case 语句后，程序流不能跳至下一 case 语句
int var = 100;
switch (var) 
{ 
    case 100: Console.WriteLine("<Value is 100>"); // 这里没有 break 
    case 200: Console.WriteLine("<Value is 200>"); break; 
}  
而在 C# 中你将得到一个编译时错误：
error CS0163: Control cannot fall through 
from one case label ('case 100:') to another

2.然而你可以像在 C++ 中一样这么用：
switch (var) 
{
    case 100: 
    case 200: Console.WriteLine("100 or 200<VALUE is 200>"); break; 
} 

3.你还可以用常数变量作为 case 值：
例子：
const string WeekEnd = "Sunday";
const string WeekDay1 = "Monday"; 
....

string WeekDay = Console.ReadLine();
switch (WeekDay ) 
{ 
case WeekEnd: Console.WriteLine("It's weekend!!"); break; 
case WeekDay1: Console.WriteLine("It's Monday"); break;
}  

委托
委托让我们可以把函数引用保存在变量中。这就像在 C++ 中使用 typedef 保存函数指针一样。 
delegate int Operation(int val1, int val2);
public int Add(int val1, int val2) 
{ 
    return val1 + val2; 
}
public int Subtract (int val1, int val2) 
{ 
    return val1- val2;
} 
public void Perform()
{
    Operation Oper;
    Console.WriteLine("Enter + or - ");
    string optor = Console.ReadLine();
    Console.WriteLine("Enter 2 operands");
            
    string opnd1 = Console.ReadLine();
    string opnd2 = Console.ReadLine();
            
    int val1 = Convert.ToInt32 (opnd1);            
    int val2 = Convert.ToInt32 (opnd2);
            
    if (optor == "+")
        Oper = new Operation(Add);
    else
        Oper = new Operation(Subtract);
        
    Console.WriteLine(" Result = {0}", Oper(val1, val2));
}

继承与多态
C# 只允许单一继承。多重继承可以通过接口达到。 
class Shape {
public virtual void Draw(){
    Console.WriteLine("Shape.Draw")    ;
} 
}

class Rectangle : Shape {
public override void Draw(){
    Console.WriteLine("Rectangle.Draw");
}     
}

使用“new”隐藏父类函数 (定义子类自己的方法，不能实现多态，多态须通过override实现)
class Shape
{
    public virtual void Draw()
    {
        Console.WriteLine("Shape.Draw")    ;
    }
} 
class Rectangle : Shape
{
    public new void Draw()
    {
        Console.WriteLine("Rectangle.Draw");
    }            
}
class Square : Rectangle
{
    //这里不用 override
    public new void Draw() 
    {
        Console.WriteLine("Square.Draw");
    }
}
class MainClass
{
    static void Main(string[] args)
    {
        Console.WriteLine("Using Polymorphism:");
        Shape[] shp = new Shape[3];
        Rectangle rect = new Rectangle();
            
        shp[0] = new Shape();
        shp[1] = rect;
        shp[2] = new Square();
                        
        shp[0].Draw();
        shp[1].Draw();
        shp[2].Draw();
            
        Console.WriteLine("Using without Polymorphism:");
        rect.Draw();            
        Square sqr = new Square();
        sqr.Draw();
    }
}    
    
Output:
Using Polymorphism
Shape.Draw
Shape.Draw
Shape.Draw
Using without Polymorphism:
Rectangle.Draw
Square.Draw 
多态性认为 Rectangle 类的 Draw 方法是和 Shape 类的 Draw 方法不同的另一个方法，而不是认为是其多态实现。
所以为了防止父类和子类间的命名冲突，我们只有使用 new 修饰符
注意：你不能在一个类中使用一个方法的两个版本，一个用 new 修饰符，另一个用 override 或 virtual。
就像在上面的例子中，我不能在 Rectangle 类中增加另一个名为 Draw 的方法，因为它是一个 virtual 或 override 的方法。
同样在 Square 类中，我也不能重写 Shape 类的虚方法 Draw.

调用基类成员 
public Child(int val) :base(val) {
    myVar = 5;
    base.myVar;
}
 
OR

public Child(int val) {
    base(val);
    myVar = 5 ;
    base.myVar;
} 
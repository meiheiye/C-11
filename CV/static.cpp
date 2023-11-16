/*
1.修饰普通变量:
    修改变量的存储区域和生命周期，使变量存储在静态区，在 main 函数运行前就分配了空间，如果有初始值就用初始值初始化它，如果没有初始值系统用默认值初始化它。
2.修饰普通函数:
    表明函数的作用范围，仅在定义该函数的文件内才能使用。在多人开发项目时，为了防止与他人命令函数重名，可以将函数定位为 static。
3.修饰成员变量:
    修饰成员变量使所有的对象只保存一个该变量，而且不需要生成对象就可以访问该成员。
4.修饰成员函数:
    修饰成员函数使得不需要生成对象就可以访问该函数，但是在 static 函数内不能访问非静态成员。
*/
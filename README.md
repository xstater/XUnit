# XUnit
一个简单的单位换算器

### Example
    unit_cast<unit::GB>(unit::KB(10086)).value();//千字节换算吉塔字节
    unit_cast<unit::kilogram>(unit::carat(13)).value();//克拉换算千克
    unit_cast<unit::kilometer>(unit::gram(100)).value();//克换算千米，错误，静态断言不通过

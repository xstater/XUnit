# XUnit
一个简单的单位换算器

### Example
        cout << unit_cast<MB>(GB(10086)).value() << "MB" << endl;
        cout << unit_cast<kilogram>(carat(13)).value() << "kg" << endl;
        cout << unit_cast<centimeter>(centimeter(10) + meter(0.1)).value() << "cm" << endl;
        cout << (centimeter(13)+=meter(0.13)).value() << "cm" << endl;
        //cout << unit_cast<kilometer>(gram(100)).value() << endl;//克换算千米，错误，静态断言不通过
-------
        1.03281e+07MB
        0.0026kg
        20cm
        26cm
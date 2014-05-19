**************************************************
Project from LO21 - UTC (France)

Made by Mike GREVELINGER & Baptiste NOGARET

Use it, but why would you do it ?

**************************************************

Organisation:
    - resources : images, sounds, ...
    - src : for the code
        - class
        - gui
        - database : database file + library
        - enumeration : includes all the enum class + their methods, ...
    - doc : from doxygen + our UML
    - test : for unit test (http://qt-project.org/doc/qt-4.8/qtestlib-tutorial1.html)
    

**************************************************

In SQLite any column, with the exception of an INTEGER PRIMARY KEY column, may be used to store any type of value. For instance, a column declared as INTEGER may contain an integer value in one row and a text value in the next. This is due to SQLite associating the type of a value with the value itself rather than with the column it is stored in. A consequence of this is that the type returned by QSqlField::type() only indicates the field's recommended type. No assumption of the actual type should be made from this and the type of the individual values should be checked.

From : https://qt-project.org/doc/qt-4.7/sql-driver.html#id-9b44f273-b5f2-43ed-8d86-7e17637b4a20

**************************************************
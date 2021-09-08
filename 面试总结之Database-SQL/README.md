# 面试总结之Database / SQL

## DATABASE

* 什么是数据库事务？
  * [数据库事务_百度百科](https://baike.baidu.com/item/%E6%95%B0%E6%8D%AE%E5%BA%93%E4%BA%8B%E5%8A%A1/9744607?fr=aladdin)
  * 一个逻辑工作单元要成为事务，必须满足所谓的ACID（原子性（atomicity，或称不可分割性）、一致性（consistency）、隔离性（isolation，又称独立性）、持久性（durability)）属性。
* 索引如何实现？
  * [数据库索引_百度百科](https://baike.baidu.com/item/%E6%95%B0%E6%8D%AE%E5%BA%93%E7%B4%A2%E5%BC%95/8751686?fr=aladdin)
  * 存储为文件
* lock
  * [What is lock (database)? - SQL Server Comparison Expert](http://www.databasecompare.com/What-is-lock-(database).html)
* [详解面试中常考的数据库「锁」问题](https://mp.weixin.qq.com/s/QI4ahAkPzrpprLCDDi4oDA)
* 机器Crash之后数据如何备份恢复？
* [面试中有哪些经典的数据库问题？ - 数据库开发](https://mp.weixin.qq.com/s/_2YGz3FA3et7KhcOzqM7PA)
* [腾讯面试：一条SQL语句执行得很慢的原因有哪些？](https://mp.weixin.qq.com/s/2o0iS4LVzl5PDz1zTILnLw)
* [面试官：数据量很大，分页查询很慢，怎么优化？](https://mp.weixin.qq.com/s/sSjhf7B5v7l6HzoWtP9_9Q)
  * http://uusama.com/458.html
* [面试官：给我讲一下分库分表方案](https://mp.weixin.qq.com/s/RKZKr2uXGyLcIbec5RZ_eg)
  * https://www.cnblogs.com/littlecharacter/p/9342129.html
* [一个高频面试题：怎么保证缓存与数据库的双写一致性？](https://blog.csdn.net/chang384915878/article/details/86756463)
* [【字节二面】缓存一致性如何保证？ (qq.com)](https://mp.weixin.qq.com/s/-hvhV3GFef4BeDRRUFY6yw)
* [面试常考！缓存三大问题及解决方案](https://mp.weixin.qq.com/s/HUWuVmfnOBCJJJRt7__EFA)
  * https://juejin.im/post/5b604b9ef265da0f62639001
* [高并发之存储篇：关注下索引原理和优化吧！ (qq.com)](https://mp.weixin.qq.com/s/xmAhtJXFNkmOR4Cko9e-cQ)
* [面试官：数据库自增ID用完了会怎么样？ (qq.com)](https://mp.weixin.qq.com/s/iZPBpq2hVL6NdbGz-gcPTw)

## MYSQL
* [面试官：谈谈你对MySQL索引的认识？](https://mp.weixin.qq.com/s/NRapquVpiqynt4BOUCwCoQ)
* [面试小知识：MySQL索引相关 - 数据库开发](https://mp.weixin.qq.com/s/j-meke0QMqTgPInj118UZA)
* [面试官：为什么 MySQL 的索引要使用 B+ 树，而不是其它树？比如 B 树？](https://mp.weixin.qq.com/s/k1BqFgc2ck_HR5Q6HmnNWQ)
  * https://www.cnblogs.com/leefreeman/p/8315844.html
* [【面试现场】为什么 MySQL 数据库要用B+树存储索引？](https://mp.weixin.qq.com/s/XN8PyiRFOyHAh6HLuTlD1Q)
* [MySQL 如何查找删除重复行？ - 数据库开发](https://mp.weixin.qq.com/s/qKoXTjdupjY25k6_-7PwxA)
* [面试官：MySQL 表设计要注意什么？](https://mp.weixin.qq.com/s/TGvLTVUIg6Lam9CfjALLGQ)
* [MySQL 优化面试解析](https://mp.weixin.qq.com/s/awRZ3fmN879MtuuZ2cb9pw)
  * http://www.zhenganwen.top/articles/2018/12/25/1565048860202.html
* [面试 | 巧用 explain 优化 MySQL 语句](https://mp.weixin.qq.com/s/OnfMdisiJ_f-HgIyOvc0qw)
* [什么是MySQL的执行计划（Explain关键字）？ (qq.com)](https://mp.weixin.qq.com/s/E8wJQvldwEAzxK5mEuFhog)
* [MySQL 面试，必须掌握的 8 个知识点](https://mp.weixin.qq.com/s/MKOoKuymUr-ZUVOT6jKfQg)
* [MySQL的COUNT语句](https://mp.weixin.qq.com/s/UZgBdR_j1Oi2KK8XN7tGbQ)
* [100 道 MySQL 数据库经典面试题解析 (qq.com)](https://mp.weixin.qq.com/s/0Rahp4jZIngs14HFh2mToQ)
* [很用心的为你写了 9 道 MySQL 面试题 (qq.com)](https://mp.weixin.qq.com/s/6FKthnz2NaykgB1nrGjI4Q)
* [MySQL 海量数据优化（理论+实战）(qq.com)](https://mp.weixin.qq.com/s/z7iiHa-dLoHf651Gx52SQA)
* [为什么 MySQL 使用 B+ 树 (qq.com)](https://mp.weixin.qq.com/s/71PL1-0hx7MFwlJhvKLHpg)
* [Mysql 夺命连环 13 问，你能抗住多少题？ (qq.com)](https://mp.weixin.qq.com/s/ovNswH3FrnqO4RZ7TItRaA)
* [阿里二面，为什么MySQL选择Repeatable Read作为默认隔离级别？ (qq.com)](https://mp.weixin.qq.com/s/bbtrO4ZP-5KnQ_XWXQh1sA)

## REDIS
* [Redis 常见面试题请收好 | 原力计划 (qq.com)](https://mp.weixin.qq.com/s/a_OU80touv7RVXosy6YULw)
* [美团二面：Redis与MySQL双写一致性如何保证？ (qq.com)](https://mp.weixin.qq.com/s/N4LZwRRvj95ZavZewG0adw)

## SQL
* [破解面试难题8个角度带你解读SQL面试技巧！ (qq.com)](https://mp.weixin.qq.com/s/BvGSzmKBSBBcnS84xh_M7w)
* [我说 SELECT COUNT(*) 会造成全表扫描 (qq.com)](https://mp.weixin.qq.com/s/NZjPYa2YA3K7OY_-hqdmhA)
* [数据科学家常见的5个SQL面试问题 (qq.com)](https://mp.weixin.qq.com/s/7n8EC3qqpZfWa4OybLPCMA)
* [经典 SQL 笔试面试题：求解连续区间 (qq.com)](https://mp.weixin.qq.com/s/i2gnSquBWh_HKKiy4OUQCQ)

1. 现有一张学生表，有只有一个列是名字，请选出其中的重名的学生的名字
select name from student group by name having count(*) > 1

2. 从公司员工工资表中选出所有部门平均工资大于公司平均工资的部门里的所有员工记录

select * from company where department in (select department 
from company 
group by deparment 
having avg(salary) > (select avg(salary) from company)
) 

3. Given the two following tables.
Names
Name Number
Wayne Gretzky 99
Jaromir Jagr 68
Bobby Orr 4
Bobby Hull 23
Brett Hull 16
Mario Lemieux 66
Steve Yzerman 19
Claude Lemieux 19
Mark Messier 11
Mats Sundin 13

Points
Name Points
Wayne Gretzky 244
Jaromir Jagr 168
Bobby Orr 129
Bobby Hull 93
Brett Hull 121
Mario Lemieux 109
Joe Sakic 94

Write SQL statement to display the player’s Names, numbers and points for all players represented by an entry in both tables?

Answer: A. SELECT names.name, names.number, points.points FROM names INNER JOIN points ON names.name=points.name

A. SELECT names.name, names.number, points.points FROM names INNER JOIN points ON names.name=points.name
B. SELECT names.name, names.number, points.points FROM names FULL OUTER JOIN points ON names.name=points.name
C. SELECT names.name, names.number, points.points FROM names LEFT OUTER JOIN points ON names.name=points.name
D. SELECT names.name, names.number, points.points FROM names RIGHT OUTER JOIN points ON names.name=points.name

4. Given

STAFF
id INTEGER
name CHAR(20)
dept INTEGER
job CHAR(20)
years INTEGER
salary DECIMAL(10, 2)
comm. DECIMAL(10, 2)

Write a SQL sentence to retrun total number of employees in each department with corresponding department id under the following conditions:
Only return departments with at least one employee receiving a commission greater than 5000. The results should be sorted by the department count from most to least

Answer, B. SELECT dept, COUNT (*) FROM staff GROUP BY dept HAVING comm.>5000 ORDER BY 1 DESC

A. SELECT dept, COUNT(id) FROM staff WHERE comm>5000 GROUP BY dept ORDER BY 1 DESC
B. SELECT dept, COUNT (*) FROM staff GROUP BY dept HAVING comm.>5000 ORDER BY 1 DESC
C. SELECT dept, COUNT(*) FROM staff WHERE comm.>5000 GROUP BY dept, comm. ORDER BY 2 DESC
D. SELECT dept, comm, COUNT(id) FROM staff WHERE comm.>5000 GROUP BY dept, comm ORDER BY 3 DESC

5. Given the two following table definitions

ORG
deptnumb INTEGER
deptname CHAR(30)
manager INTEGER
division CHAR(30)
location CHAR(30)

STAFF
id INTEGER
name CHAR(30)
dept INTEGER
job CHAR(20)
years INTEGER
salary DECIMAL(10, 2)
comm DECIMAL(10, 2)

Write a SQL statement to display each department by name, and the total salary of all employees in the department?

Answer, C. SELECT a.deptname, SUM(b.salary) FROM org a, staff b WHERE a.deptnumb=b.dept GROUP BY a.deptname

A. SELECT a.deptname, SUM(b.salary) FROM org a, staff b WHERE a.deptnumb=b.dept ORDER BY a.deptname
B. SELECT b.deptname, SUM(a.salary) FROM org a, staff b WHERE a.deptnumb=b.dept ORDER BY a.deptname
C. SELECT a.deptname, SUM(b.salary) FROM org a, staff b WHERE a.deptnumb=b.dept GROUP BY a.deptname
D. SELECT b.deptname, SUM(a.salary) FROM org a, staff b WHERE a.deptnumb=b.dept GROUP BY a.deptname 

### Understanding of table, view and index.
Given tables as follows:

T1
Col1 Col2
1 10
2 20
3 20
4 30
5 30
6 30

T2
Col1 Col2
1 10
2 20
3 30
4 40
5 50
6 60

1. Please write a query based on T1 and T2 which produces:
ColA ColB
1 10
2 20
3 20
3 30
4 30
4 40
5 30
5 50
6 30
6 60
(Hint: the result set is produced from merging T1 and T2 together, without duplicate values)

2. Please write a query based on T1 which produces:

Col2

20

30

Note that DON'T use hard coded 'where clause' to simply 'select distinct col2 from t1 where col2 = 20 or col2 = 30'.

( Hint: 20 and 30 apprear more than once in col2 of T1)

3. Please write the result of the following query:
select A.col1, B.col1, A.col2, B.col2 from T1 A FULL OUTER JOIN T2 B ON (A.col2 = B.col2);

4. Please list the database objects you know (for example, table is one of the objects). Describe how to use them and why do you use them.

5. How many kinds of keys in database? How to use them?

6. We want to prevent the users from inserting the values larger than 100 for col1 in T1 (above table). How do you do that?

7. User A is doing some modifications on T1, and he does not want other users to know what he has changed until he commit all his work. What options could he have?

8. How to return values from a store procedure? How to return result set from a store procedure?

9. How do I add another column Col3 to T1, with data type integer and default value 100?

10. Describe how to use 'CURSOR' in SQL procedure. Please write a procedure that uses CURSOR to return result set with 'select col1 from t1'.

## General Questions of SQL SERVER 
* What is Cursor?
  * Cursor is a database object used by applications to manipulate data in a set on a row-by-row basis, instead of the typical SQL commands that operate on all the rows in the set at one time.
  * In order to work with a cursor we need to perform some steps in the following order:
  * Declare cursor
  * Open cursor
  * Fetch row from the cursor
  * Process fetched row
  * Close cursor
  * Deallocate cursor (Read More Here)
* What is Collation?
  * Collation refers to a set of rules that determine how data is sorted and compared. Character data is sorted using rules that define the correct character sequence, with options for specifying case sensitivity, accent marks, kana character types and character width. (Read More Here)
* What is Difference between Function and Stored Procedure?
  * UDF can be used in the SQL statements anywhere in the WHERE/HAVING/SELECT section where as Stored procedures cannot be. UDFs that return tables can be treated as another rowset. This can be used in JOINs with other tables. Inline UDF’s can be thought of as views that take parameters and can be used in JOINs and other Rowset operations.
* What is sub-query? Explain properties of sub-query?
  * Sub-queries are often referred to as sub-selects, as they allow a SELECT statement to be executed arbitrarily within the body of another SQL statement. A sub-query is executed by enclosing it in a set of parentheses. Sub-queries are generally used to return a single row as an atomic value, though they may be used to compare values against multiple rows with the IN keyword.
  * A subquery is a SELECT statement that is nested within another T-SQL statement. A subquery SELECT statement if executed independently of the T-SQL statement, in which it is nested, will return a resultset. Meaning a subquery SELECT statement can standalone and is not depended on the statement in which it is nested. A subquery SELECT statement can return any number of values, and can be found in, the column list of a SELECT statement, a FROM, GROUP BY, HAVING, and/or ORDER BY clauses of a T-SQL statement. A Subquery can also be used as a parameter to a function call. Basically a subquery can be used anywhere an expression can be used. (Read More Here)
* What are different Types of Join?
  * Cross Join
    * A cross join that does not have a WHERE clause produces the Cartesian product of the tables involved in the join. The size of a Cartesian product result set is the number of rows in the first table multiplied by the number of rows in the second table. The common example is when company wants to combine each product with a pricing table to analyze each product at each price.
  * Inner Join
    * A join that displays only the rows that have a match in both joined tables is known as inner Join.  This is the default type of join in the Query and View Designer.
  * Outer Join
    * A join that includes rows even if they do not have related rows in the joined table is an Outer Join.  You can create three different outer join to specify the unmatched rows to be included:
  * Left Outer Join: 
    * In Left Outer Join all rows in the first-named table i.e. “left” table, which appears leftmost in the JOIN clause are included. Unmatched rows in the right table do not appear. 
  * Right Outer Join: 
    * In Right Outer Join all rows in the second-named table i.e. “right” table, which appears rightmost in the JOIN clause are included. Unmatched rows in the left table are not included.
  * Full Outer Join: 
    * In Full Outer Join all rows in all joined tables are included, whether they are matched or not.
  * Self Join
    * This is a particular case when one table joins to itself, with one or two aliases to avoid confusion. A self join can be of any type, as long as the joined tables are the same. A self join is rather unique in that it involves a relationship with only one table. The common example is when company has a hierarchal reporting structure whereby one member of staff reports to another. Self Join can be Outer Join or Inner Join. (Read More Here)
* What are primary keys and foreign keys?
  * Primary keys are the unique identifiers for each row. They must contain unique values and cannot be null. Due to their importance in relational databases, Primary keys are the most fundamental of all keys and constraints. A table can have only one Primary key.
Foreign keys are both a method of ensuring data integrity and a manifestation of the relationship between tables.
* What is User Defined Functions? What kind of User-Defined Functions can be created?
  * User-Defined Functions allow defining its own T-SQL functions that can accept 0 or more parameters and return a single scalar data value or a table data type.
  * Different Kinds of User-Defined Functions created are: 
    * Scalar User-Defined Function
      * A Scalar user-defined function returns one of the scalar data types. Text, ntext, image and timestamp data types are not supported. These are the type of user-defined functions that most developers are used to in other programming languages. You pass in 0 to many parameters and you get a return value.
    * Inline Table-Value User-Defined Function
      * An Inline Table-Value user-defined function returns a table data type and is an exceptional alternative to a view as the user-defined function can pass parameters into a T-SQL select command and in essence provide us with a parameterized, non-updateable view of the underlying tables.
    * Multi-statement Table-Value User-Defined Function
      * A Multi-Statement Table-Value user-defined function returns a table and is also an exceptional alternative to a view as the function can support multiple T-SQL statements to build the final result where the view is limited to a single SELECT statement. Also, the ability to pass parameters into a TSQL select command or a group of them gives us the capability to in essence create a parameterized, non-updateable view of the data in the underlying tables. Within the create function command you must define the table structure that is being returned. After creating this type of user-defined function, It can be used in the FROM clause of a T-SQL command unlike the behavior found when using a stored procedure which can also return record sets. (Read Here For Example)
* What is Identity?
  * Identity (or AutoNumber) is a column that automatically generates numeric values. A start and increment value can be set, but most DBA leave these at 1. A GUID column also generates numbers; the value of this cannot be controlled. Identity/GUID columns do not need to be indexed.
* What is DataWarehousing?
  * Subject-oriented, meaning that the data in the database is organized so that all the data elements relating to the same real-world event or object are linked together;
  * Time-variant, meaning that the changes to the data in the database are tracked and recorded so that reports can be produced showing changes over time;
  * Non-volatile, meaning that data in the database is never over-written or deleted, once committed, the data is static, read-only, but retained for future reporting.
  * Integrated, meaning that the database contains data from most or all of an organization’s operational applications, and that this data is made consistent.

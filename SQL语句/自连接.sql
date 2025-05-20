--自连接
--1.查询员工 及其 所属领导的名字
--表结构：emp
select a.name 领导 , b.name 员工 from emp a , emp b where a.managerid = b.id;
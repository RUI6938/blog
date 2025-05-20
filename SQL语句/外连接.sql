--外连接演示
--1.查询emp表的所有数据，和对应的部门信息（左外连接）
--表结构:emp,dept
--连接条件：emp.dept_id = dept_id
select e.* , d.name from emp e left outer join dept d on e.dept_id = d.id;

select e.* , d.name from emp e left join dept d on e.dept_id = d.id;

--2.查询dept表的所以数据，和对应的员工信息（右外连接）
select d.* , e.* from emp e right outer join dept d on e.dept_id = d.id;
--或者
select d.* , e.* from dept d left outer join emp e on e.dept_id = d.id;


--内连接演示
--1.查询每一个员工的姓名，及关联的部门的名称（隐式内连接实现）
--表结构:emp,dept
--连接条件：emp.dept_id = dept_id

select emp.name,dept.name from emp,dept where emp.dept_id = dept.id;

select e.name , d.name from emp e , dept d where e.dept_id = d.id;

--2.查询每一个员工的姓名，及关联的部门的名称（显示内连接实现）
select e.name , d.name from emp e inner join dept d on e.dept_id = d.id;

select e.name , d.name from emp e join dept d on e.dept_id = d.id;

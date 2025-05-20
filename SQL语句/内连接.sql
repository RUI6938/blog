--内连接演示
--1.查询每一个员工的姓名，及关联的部门的名称（隐式内连接实现）
--表结构:emp,dept
--连接条件：emp.dept_id = dept_id

select emp.name,dept.name from emp,dept where emp.dept_id = dept.id;

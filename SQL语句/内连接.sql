--��������ʾ
--1.��ѯÿһ��Ա�����������������Ĳ��ŵ����ƣ���ʽ������ʵ�֣�
--��ṹ:emp,dept
--����������emp.dept_id = dept_id

select emp.name,dept.name from emp,dept where emp.dept_id = dept.id;

select e.name , d.name from emp e , dept d where e.dept_id = d.id;

--2.��ѯÿһ��Ա�����������������Ĳ��ŵ����ƣ���ʾ������ʵ�֣�
select e.name , d.name from emp e inner join dept d on e.dept_id = d.id;

select e.name , d.name from emp e join dept d on e.dept_id = d.id;

--��������ʾ
--1.��ѯemp����������ݣ��Ͷ�Ӧ�Ĳ�����Ϣ���������ӣ�
--��ṹ:emp,dept
--����������emp.dept_id = dept_id
select e.* , d.name from emp e left outer join dept d on e.dept_id = d.id;

select e.* , d.name from emp e left join dept d on e.dept_id = d.id;

--2.��ѯdept����������ݣ��Ͷ�Ӧ��Ա����Ϣ���������ӣ�
select d.* , e.* from emp e right outer join dept d on e.dept_id = d.id;
--����
select d.* , e.* from dept d left outer join emp e on e.dept_id = d.id;


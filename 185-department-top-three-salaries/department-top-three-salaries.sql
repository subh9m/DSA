-- Write your PostgreSQL query statement below
select d1.name as Department, e1.name as Employee, e1.salary as Salary 
from Employee e1
join
Department d1 on
e1.departmentId = d1.id
where (
    select count(distinct e2.salary)
    from Employee e2
    where e2.departmentId = e1.departmentId
    and e2.salary > e1.salary
) < 3
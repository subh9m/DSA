# Write your MySQL query statement below
select e1.name
from Employee e1
where (select count(*)
       from Employee e2
       where e2.managerId = e1.id)
       >= 5

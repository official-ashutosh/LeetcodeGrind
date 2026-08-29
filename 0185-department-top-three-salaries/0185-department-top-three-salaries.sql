# Write your MySQL query statement below
select d.name as Department, e.name as Employee, salary as Salary
from Department d, Employee e
where e.departmentId = d.id
and 3 > (
    select count(distinct(b.salary))
    from Employee b
    where b.departmentId = e.departmentId
    and b.salary > e.salary
);
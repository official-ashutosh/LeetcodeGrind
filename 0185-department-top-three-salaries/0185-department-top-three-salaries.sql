# Write your MySQL query statement below
select Department, Employee, Salary 
from (
    select d.name as Department, 
            e.name as Employee, 
            salary as Salary,
            dense_rank() over (partition by d.id
                order by salary desc
            ) as rnk
    from Employee e, Department d
    where e.departmentId = d.id
) t
where rnk <= 3;
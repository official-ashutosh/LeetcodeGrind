# Write your MySQL query statement below
select s.user_id, 
    coalesce(
        round(
            count(case when a.action = 'confirmed' then 1 end)/count(a.action) , 2), 0)
    as confirmation_rate
from Signups s
left join Confirmations a
on s.user_id = a.user_id
group by s.user_id;
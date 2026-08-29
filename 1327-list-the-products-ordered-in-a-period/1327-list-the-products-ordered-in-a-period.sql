# Write your MySQL query statement below
select product_name, sum(unit) as unit
from Products p, Orders o
where p.product_id = o.product_id 
and month(order_date) = 2 and year(order_date) = 2020
group by o.product_id
having sum(unit) >= 100;
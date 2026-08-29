# Write your MySQL query statement below
select p.product_name, sum(o.unit) as unit
from Products p, Orders o
where p.product_id = o.product_id 
and date_format(o.order_date, "%Y-%m") = "2020-02"
group by o.product_id
having sum(unit) >= 100;
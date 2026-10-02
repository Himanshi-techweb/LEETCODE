# Write your MySQL query statement below
select a.product_name,s.year,s.price
from Sales as s
LEFT JOIN Product as a
on s.product_id=a.product_id;

# Write your MySQL query statement below
select a.product_id ,
round(IFNULL(sum(a.price*u.units)/sum(u.units),0),2) as average_price
from Prices as a
left join UnitsSold as u
  on a.product_id=u.product_id
  and u.purchase_date BETWEEN a.start_date and a.end_date
group by a.product_id;

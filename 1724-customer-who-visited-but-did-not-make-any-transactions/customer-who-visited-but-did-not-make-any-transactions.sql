# Write your MySQL query statement below
select a.customer_id ,count(a.visit_id) as count_no_trans
from Visits as a
Left Join Transactions as b
   on b.visit_id =a.visit_id
where b.transaction_id is NULL
group by a.customer_id;
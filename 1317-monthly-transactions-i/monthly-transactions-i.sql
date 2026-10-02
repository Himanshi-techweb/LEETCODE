# Write your MySQL query statement below
select DATE_FORMAT(q.trans_date,'%Y-%m') as month,
q.country ,
count(q.amount) as trans_count,
sum(q.state="approved") as approved_count,
sum(q.amount) as trans_total_amount,
sum(IF(q.state="approved",q.amount,0)) as approved_total_amount
from Transactions as q
group by q.country,DATE_FORMAT(q.trans_date,'%Y-%m');


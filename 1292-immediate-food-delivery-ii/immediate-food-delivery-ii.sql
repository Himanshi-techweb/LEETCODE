select 
round(avg(b.order_date=b.customer_pref_delivery_date)*100,2) AS immediate_percentage
from Delivery as b
WHERE 
(customer_id,order_date) IN (select a.customer_id,min(a.order_date) 
from Delivery as a
group by a.customer_id);
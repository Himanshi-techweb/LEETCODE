# Write your MySQL query statement below
select distinct a.id 
from Weather as a
join Weather as b
   on DATEDIFF(a.recordDate,b.recordDate)=1
where a.temperature >b.temperature;


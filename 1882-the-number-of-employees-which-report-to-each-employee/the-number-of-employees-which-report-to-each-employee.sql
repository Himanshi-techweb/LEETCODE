# Write your MySQL query statement below
select e.employee_id,e.name,m.reports_count,m.average_age
from Employees as e
INNER JOIN
(select reports_to,count(employee_id) as reports_count,round(avg(age)) as average_age
from Employees
group by reports_to
having count(employee_id)>=1)
m on e.employee_id=m.reports_to
order by e.employee_id;

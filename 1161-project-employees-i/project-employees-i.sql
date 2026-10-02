# Write your MySQL query statement below
select project_id ,ROUND(IFNULL(sum(e.experience_years)/count(a.employee_id),0),2) as average_years
from Project as a
left join Employee as e
  on a.employee_id=e.employee_id

group by a.project_id;

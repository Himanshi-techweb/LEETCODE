# Write your MySQL query statement below
select e.name
from Employee as e
where e.id IN (
    select managerId 
    from Employee
    group by managerId
    having count(id)>=5
);
# Write your MySQL query statement below
select r.contest_id , round(IFNULL((count(r.contest_id)/(select count(*) from Users))*100,0),2) as percentage
from Register as r
left join Users as u
  on u.user_id=r.user_id
group by r.contest_id
order by percentage DESC,contest_id ASC;
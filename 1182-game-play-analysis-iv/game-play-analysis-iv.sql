# Write your MySQL query statement below
select 
round(sum(DATEDIFF(b.event_date,a.event_date)=1)/(select count(distinct player_id ) from Activity),2) as fraction
from Activity as a
join Activity as b
where a.player_id=b.player_id and (a.player_id,a.event_date) IN 
(
    Select player_id,min(event_date)
    from Activity 
    group by player_id
)  ;



# Write your MySQL query statement below=

select project_id,
ROUND(sum(experience_years)/count(Distinct p.employee_id), 2) as average_years
from project p
left join employee e 
on p.employee_id = e.employee_id
group by project_id




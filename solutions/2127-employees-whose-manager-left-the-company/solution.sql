# Write your MySQL query statement below

select e1.employee_id
from Employees e1
where e1.salary < 30000
and e1.manager_id is not null
and not exists (
select 1 from Employees e2
where e2.employee_id = e1.manager_id
)
order by e1.employee_id

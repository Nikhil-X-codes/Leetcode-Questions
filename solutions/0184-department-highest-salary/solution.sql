# Write your MySQL query statement below


select d.name AS Department,
       e.name AS Employee,
       e.salary AS Salary
from Employee e
left join Department d
on e.departmentId = d.id

where e.salary = (
    select MAX(salary)
    from Employee
    where departmentId = d.id
)

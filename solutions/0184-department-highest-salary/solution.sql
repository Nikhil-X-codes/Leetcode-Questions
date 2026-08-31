# Write your MySQL query statement below

select d.name as Department,
e.name as Employee,
e.salary as Salary
from

(
select * , DENSE_RANK() over(
     PARTITION by departmentId
    order by salary DESC
) as rnk
from Employee

)e

left join Department d
on e.departmentId = d.id
WHERE e.rnk = 1;

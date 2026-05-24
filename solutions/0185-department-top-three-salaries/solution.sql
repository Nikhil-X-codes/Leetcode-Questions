# Write your MySQL query statement below

select d.name as Department,
e.name as Employee,e.Salary as Salary
from (
    select *,
    DENSE_RANK() OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rnk
    FROM Employee
) e
JOIN Department d
ON e.departmentId = d.id
WHERE e.rnk <= 3;

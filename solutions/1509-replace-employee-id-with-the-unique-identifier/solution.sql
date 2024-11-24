# Write your MySQL query statement below

SELECT e.unique_id,emp.name FROM EmployeeUNI e
RIGHT JOIN Employees emp ON e.id = emp.id;

